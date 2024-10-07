#ifndef UNIT_SERVICE_ORDER_HPP
#define UNIT_SERVICE_ORDER_HPP

class UnitServiceOrder {
    public:

        void runUnitTests();

    private:
        bool unit_testSetAndGetOrderName();
        bool unit_testSetAndGetEquipment();
        bool unit_testSetAndGetSector();
        bool unit_testSetAndGetPriority();
        bool unit_testSetAndGetDeadline();
        bool unit_testSetAndGetOrderType();
        bool unit_testSetAndGetErrorDescription();
        bool unit_testSetAndGetPostedState();
};

#endif