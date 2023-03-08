// Name: Pawan Deep
// Seneca Student ID: 111144218
// Seneca email: pdeep1@myseneca.ca
// Date of completion: 08/07/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <utility>
#include <fstream>
#include <algorithm>

#include "LineManager.h"
#include "Utilities.h"

using namespace std;
namespace sdds {
    LineManager::LineManager(const string& file, vector<Workstation*> stations) {
        string record = "";
        string str1 = "";
        string str2 = "";
        ifstream f(file);
        bool ans = false;
        int i = 0;
        while (f.eof() == false) {
            getline(f, record);
            Utilities utilities;
            utilities.setDelimiter('|');
            size_t pos = 0;
            bool more = true;
            str1 = utilities.extractToken(record, pos, more);
            if (more==true) {
                str2 = utilities.extractToken(record, pos, more);
            }
            else {
                str2 = "";
            }
            vector<Workstation*>::iterator it;
            it = find_if(stations.begin(), stations.end(), [&str1](Workstation* ws) {
                bool ans = true;
                if (ws->getItemName() != str1) {
                    ans = false;
                }
                return ans;
            });
            if (it != stations.end()) {
                Workstation* ws = stations.at(distance(stations.begin(), it));
                m_activeLine.push_back(ws);
                if (ans==true) {
                    m_firstStation = ws;
                    ans = false;
                }
                if (str2 != "") {
                    it = find_if(stations.begin(), stations.end(),[&str2](Workstation* ws) {
                        bool ans = true;
                        if (ws->getItemName() != str2) {
                            ans = false;
                        }
                        return ans;
                    });
                    if (it != stations.end()) {
                        ws->setNextStation(stations.at(distance(stations.begin(), it)));
                    }
                }
                else {
                    ans = true;
                }
            }
            i++;
        }
        f.close();
    }

    void LineManager::display(ostream& os) const {
        for (Workstation* ws : m_activeLine) {
            ws->display(os);
        }
    }

    bool LineManager::run(ostream& os) {
        static int counter = 0;
        bool ret = true;
        bool ans;
        ++counter;
        os << "Line Manager Iteration: " << counter << endl;
        if (g_pending.empty()==false && m_firstStation->m_orders.empty()==true) {
            while (g_pending.empty() == false) {
                *m_firstStation += move(g_pending.front());
                g_pending.pop_front();
            }
            return false;
        }
        for (Workstation* i : m_activeLine) {
            ans = true;
            while (ans==true && i->attemptToMoveOrder()) {
                if (i->m_orders.empty()==false) {
                    if ((i->m_orders.front().isItemFilled(i->getItemName()) == false) || i->getQuantity() == 0) {
                        ans = false;
                    }
                }
            }
            if (i->m_orders.empty()==false) {
                ret = false;
            }
            i->fill(os);
        }
        return ret;
    }

    void LineManager::reorderStations() {
        vector<Workstation*> vec_work;
        Workstation* ws = m_firstStation;
        do {
            vec_work.push_back(ws);
            ws = ws->getNextStation();
        } while (ws != nullptr);
        m_activeLine = move(vec_work);
    }
}