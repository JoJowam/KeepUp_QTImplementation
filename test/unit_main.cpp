#include "unit/UnitServiceOrder.hpp"
#include "unit/UnitFactory.hpp"

int main() {
    UnitServiceOrder unitServiceOrder;
    UnitFactory unitFactory;
    
    unitServiceOrder.runUnitTests();
    unitFactory.runUnitTests();
    return 0;
}
