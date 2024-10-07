#include "UnitServiceOrder.hpp"
#include "UnitFactory.hpp"

int main() {
    UnitServiceOrder unitServiceOrder;
    UnitFactory unitFactory;
    
    unitServiceOrder.runUnitTests();
    unitFactory.runUnitTests();
    return 0;
}
