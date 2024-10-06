#ifndef SERVICE_ORDER_HPP
#define SERVICE_ORDER_HPP

#include <string>

using std::string;

class ServiceOrder {
    public:
        virtual ~ServiceOrder() = default;

        //TODO: Implementar verificações dentro dos setters para iputs inconsistentes
        virtual void setOrderName(const string& name) = 0;
        virtual string getOrderName() const = 0;

        virtual void setEquipment(const string& equipment) = 0;
        virtual string getEquipment() const = 0;

        virtual void setSector(const string& sector) = 0;
        virtual string getSector() const = 0;

        //TODO: Implementar um enum para prioridades afim de evitar erros de digitação
        virtual void setPriority(const string& priority) = 0;
        virtual string getPriority() const = 0;

        virtual void setDeadline(const string& deadline) = 0;
        virtual string getDeadline() const = 0;

        virtual void setOrderType(const string& orderType) = 0;
        virtual string getOrderType() const = 0;

        virtual void setErrorDescription(const string& description) = 0;
        virtual string getErrorDescription() const = 0;
};

#endif
