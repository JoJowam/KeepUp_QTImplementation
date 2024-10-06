#ifndef FACTORYIMPL_HPP
#define FACTORYIMPL_HPP

#include "Factory.hpp"
#include "ServiceOrder.hpp"

#include <vector>
#include <algorithm> 

using std::vector;
using std::string;

class FactoryImpl : public Factory {
    private:
        vector<ServiceOrder*> serviceOrders;
        static FactoryImpl* _instance;

        FactoryImpl();
        ~FactoryImpl();

        void add(ServiceOrder* serviceOrder) override;

    public:

        static FactoryImpl* getInstance();
        static bool destroyInstance(); 

        //TODO: Criar métodos descritivos CreateFactory e DeleteFactory que delegam para getInstance e destroyInstance

        ServiceOrder* createServiceOrder(const string& name, const string& equipment, const string& sector, const string& priority, const string& deadline, const string& orderType, const string& description) override;
        bool destroyServiceOrder(ServiceOrder* serviceOrder) override;       
};

#endif
