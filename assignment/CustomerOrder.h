
#ifndef OOP_PROJECT_CUSTOMER_ORDER_H

#include <string>
#include "Station.h"

namespace sdds {

    class CustomerOrder {
      public:
        struct Item {
            std::string m_itemName;
            size_t m_serialNumber{0};
            bool m_isFilled{false};

            Item(const std::string& src) : m_itemName(src) {};
        };

        std::string m_name;
        std::string m_product;
        size_t m_cntItem;

        Item** m_lstItem;

      public:
        static size_t m_widthField;

        CustomerOrder() = default;

        CustomerOrder(const std::string& str);

        CustomerOrder(const CustomerOrder& order);

        CustomerOrder(CustomerOrder&& order) noexcept;

        CustomerOrder& operator=(CustomerOrder& order) = delete;

        CustomerOrder& operator=(CustomerOrder&& order) noexcept;

        ~CustomerOrder();

        bool isOrderFilled() const;

        bool isItemFilled(const std::string& itemName) const;

        void fillItem(Station& station, std::ostream& os);

        void display(std::ostream& os) const;
    };
}
#define OOP_PROJECT_CUSTOMER_ORDER_H

#endif
