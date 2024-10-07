#ifndef SERVICE_ORDER_IMPL_HPP
#define SERVICE_ORDER_IMPL_HPP

#include "ServiceOrder.hpp"

class ServiceOrderImpl : public ServiceOrder {
    friend class UnitServiceOrder;

    private:
        string orderName;
        string equipment;
        string sector;
        string priority;
        string deadline;
        string orderType;
        string errorDescription;
        bool posted;

    public:
        ServiceOrderImpl(const string& name, const string& equipment, const string& sector, const string& priority, const string& deadline, const string& orderType, const string& description);

        ~ServiceOrderImpl() override = default;

        void setPostedOrderState(const bool& postedState) override;
        bool getPostedOrderState() const override;

        void setOrderName(const string& name) override;
        string getOrderName() const override;

        void setEquipment(const string& equipment) override;
        string getEquipment() const override;

        void setSector(const string& sector) override;
        string getSector() const override;

        void setPriority(const string& priority) override;
        string getPriority() const override;

        void setDeadline(const string& deadline) override;
        string getDeadline() const override;

        void setOrderType(const string& orderType) override;
        string getOrderType() const override;

        void setErrorDescription(const string& description) override;
        string getErrorDescription() const override;
};

#endif
