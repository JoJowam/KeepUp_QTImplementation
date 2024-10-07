#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <vector>
#include <string>

using std::vector;
using std::string;

class ServiceOrder;

class Factory {
    private:
        Factory(const Factory&) = delete;
        Factory& operator=(const Factory&) = delete;

    protected:
        virtual void add(ServiceOrder* serviceOrder) = 0;
        Factory() = default;

    public:
        typedef vector<ServiceOrder*>::iterator ServiceOrderIterator;

        virtual ~Factory() = default;

        static Factory* getInstance();
        static bool destroyInstance();

        virtual ServiceOrder* createServiceOrder(const string& name, const string& equipment, const string& sector, const string& priority, const string& deadline, const string& orderType, const string& description) = 0;
        virtual bool destroyServiceOrder(ServiceOrder* serviceOrder) = 0;

        virtual vector<ServiceOrder*> getAllServiceOrders() const = 0;
        virtual bool setServiceOrderPosted(ServiceOrder* serviceOrder) = 0;
};

#endif
