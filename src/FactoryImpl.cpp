#include "FactoryImpl.hpp"
#include "ServiceOrder.hpp"
#include "ServiceOrderImpl.hpp"

#include <algorithm>

FactoryImpl* FactoryImpl::_instance = nullptr;

FactoryImpl::FactoryImpl() {}

FactoryImpl::~FactoryImpl() {
    for (ServiceOrder* serviceOrder : serviceOrders) {
        delete serviceOrder;
    }
    serviceOrders.clear();
}

FactoryImpl* FactoryImpl::getInstance() {
    if (_instance == nullptr) {
        _instance = new FactoryImpl();
    }
    return _instance;
}

bool FactoryImpl::destroyInstance() {
    if (_instance != nullptr) {
        delete _instance;
        _instance = nullptr;
        return true;
    }
    return false;
}

ServiceOrder* FactoryImpl::createServiceOrder(const string& name, const string& equipment, const string& sector, const string& priority, const string& deadline, const string& orderType, const string& description) {
    ServiceOrder* serviceOrder = new ServiceOrderImpl(name, equipment, sector, priority, deadline, orderType, description);
    add(serviceOrder);
    return serviceOrder;
}

bool FactoryImpl::destroyServiceOrder(ServiceOrder* serviceOrder) {
    ServiceOrderIterator iterator = std::find(serviceOrders.begin(), serviceOrders.end(), serviceOrder);
    if (iterator != serviceOrders.end()) {
        delete serviceOrder;
        serviceOrders.erase(iterator);
        return true;
    }
    return false;
}

void FactoryImpl::add(ServiceOrder* serviceOrder) {
    serviceOrders.push_back(serviceOrder);
}

vector<ServiceOrder*> FactoryImpl::getAllServiceOrders() const {
    return serviceOrders;
}


bool FactoryImpl::setServiceOrderPosted(ServiceOrder* serviceOrder) {
    if (serviceOrder != nullptr) {
        if (!serviceOrder->getPostedOrderState()) {
            serviceOrder->setPostedOrderState(true);
            return true;
        } else {
            return false;
        }
    }
    return false;
}
