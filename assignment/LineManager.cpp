#include <utility>
#include <fstream>
#include <algorithm>

#include "LineManager.h"

using namespace sdds;
using namespace std;

LineManager::LineManager(const std::string& file, std::vector<Workstation*> stations) {
    if (file.empty()) {
        throw string("ERROR: No filename provided.");
    }
    ifstream file_(file);
    if (!file_)
        throw string("Unable to open [") + file + "] file.";

    string record;
    bool isNextFirst = false;
    int i = 0;
    while (!file_.eof()) {
        std::getline(file_, record);

        Utilities::setDelimiter('|');
        Utilities util;
        size_t pos = 0u;
        bool more = true;

        // read the line
        std::string str1 = util.extractToken(record, pos, more);
        std::string str2 = more ? util.extractToken(record, pos, more) : "";

        // search for Workstation
        vector<Workstation*>::iterator it;
        it = std::find_if(stations.begin(), stations.end(),
                          [&str1](Workstation* ws) { return ws->getItemName() == str1; });

        // if  workstation found
        if (it != stations.end()) {
            Workstation* first = stations.at(std::distance(stations.begin(), it));
            m_active_line.push_back(first);

            // set first station
            if (isNextFirst) {
                m_firstStation = first;
                isNextFirst = false;
            }

            // check next workstation exists
            if (!str2.empty()) {
                // search for Next Workstation
                it = std::find_if(stations.begin(), stations.end(),
                                  [&str2](Workstation* ws) { return ws->getItemName() == str2; });
                if (it != stations.end()) {
                    first->setNextStation(stations.at(std::distance(stations.begin(), it)));
                }
            } else {
                isNextFirst = true;
            }
        }
        i++;
    }

    run_iteration_counter = 0;

    file_.close();
}

void LineManager::display(ostream& os) const {
    for (Workstation* ws: m_active_line) {
        ws->display(os);
    }
}

bool LineManager::run(ostream& os) {
    ++run_iteration_counter;
    os << "Line Manager Iteration: " << run_iteration_counter << std::endl;

    if (!g_pending.empty() && m_firstStation->m_orders.empty()) {
        while (!g_pending.empty()) {
            *m_firstStation += std::move(g_pending.front());
            g_pending.pop_front();
        }
        return false;
    }
    if (run_iteration_counter == 11) {
        int x = 0;
        x++;
    }

    bool ret = true;
    bool inner_loop;
    for (auto& i: m_active_line) {
        // move to the next position that is workable
        inner_loop = true;
        while (inner_loop && i->attemptToMoveOrder()) {
            if (!i->m_orders.empty()) {
                if ((!i->m_orders.front().isItemFilled(i->getItemName())) || i->getQuantity() == 0) {
                    inner_loop = false;
                }
            }
        }

        if (!i->m_orders.empty()) ret = false;

        i->fill(os);
    }

    return ret;
}

void LineManager::reorderStations() {
    std::vector<Workstation*> temp;
    Workstation* start = m_firstStation;

    do {
        temp.push_back(start);
        start = start->getNextStation();
    } while (start != nullptr);

    m_active_line = std::move(temp);
}
