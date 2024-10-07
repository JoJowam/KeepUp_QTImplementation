#include "ServiceOrderImpl.hpp"

ServiceOrderImpl::ServiceOrderImpl(const string& name, const string& equipment, const string& sector, const string& priority, const string& deadline, const string& orderType, const string& description)
    : orderName(name), equipment(equipment), sector(sector), priority(priority), deadline(deadline), orderType(orderType), errorDescription(description), posted(false) {}

void ServiceOrderImpl::setPostedOrderState(const bool& postedState) {
    posted = postedState;
}

bool ServiceOrderImpl::getPostedOrderState() const {
    return posted;
}

void ServiceOrderImpl::setOrderName(const string& name) {
    orderName = name;
}

string ServiceOrderImpl::getOrderName() const {
    return orderName;
}

void ServiceOrderImpl::setEquipment(const string& equipment) {
    this->equipment = equipment;
}

string ServiceOrderImpl::getEquipment() const {
    return equipment;
}

void ServiceOrderImpl::setSector(const string& sector) {
    this->sector = sector;
}

string ServiceOrderImpl::getSector() const {
    return sector;
}

void ServiceOrderImpl::setPriority(const string& priority) {
    this->priority = priority;
}

string ServiceOrderImpl::getPriority() const {
    return priority;
}

void ServiceOrderImpl::setDeadline(const string& deadline) {
    this->deadline = deadline;
}

string ServiceOrderImpl::getDeadline() const {
    return deadline;
}

void ServiceOrderImpl::setOrderType(const string& orderType) {
    this->orderType = orderType;
}

string ServiceOrderImpl::getOrderType() const {
    return orderType;
}

void ServiceOrderImpl::setErrorDescription(const string& description) {
    this->errorDescription = description;
}

string ServiceOrderImpl::getErrorDescription() const {
    return errorDescription;
}
