#ifndef UNIT_FACTORY_HPP
#define UNIT_FACTORY_HPP

class UnitFactory {
    public:
        void runUnitTests();

    private:
        bool unit_testCreateServiceOrder();
        bool unit_testDestroyServiceOrder();
        bool unit_testGetAllServiceOrders();
        bool unit_testSetServiceOrderPosted();
        bool unit_testSingletonInstance();
        bool unit_testDestroyInstance();
};

#endif
