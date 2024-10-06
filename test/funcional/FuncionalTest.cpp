#include "../../src/FactoryImpl.hpp"
#include "../../src/ServiceOrder.hpp"

#include <iostream>
#include <cassert>

void test_createServiceOrder() {
    Factory* factory = FactoryImpl::getInstance();

    ServiceOrder* serviceOrder = factory->createServiceOrder(
        "ORDEM 1",              
        "MÁQUINA 1",            
        "SETOR 1",              
        "ALTA",      
        "10/10/2024",           
        "CORRETIVA",            
        "NECESSÁRIO ATUALIZAÇÃO DE SOFTWARE"
    );

    assert(serviceOrder->getOrderName() == "ORDEM 1");
    assert(serviceOrder->getEquipment() == "MÁQUINA 1");
    assert(serviceOrder->getSector() == "SETOR 1");
    assert(serviceOrder->getPriority() == "ALTA PRIORIDADE");
    assert(serviceOrder->getDeadline() == "10/10/2024");
    assert(serviceOrder->getOrderType() == "CORRETIVA");
    assert(serviceOrder->getErrorDescription() == "NECESSÁRIO ATUALIZAÇÃO DE SOFTWARE");

    std::cout << "Teste de criacao de ordem de serviço bem-sucedido!" << std::endl;

    factory->destroyServiceOrder(serviceOrder);
    FactoryImpl::destroyInstance();
}

int main() {
    test_createServiceOrder();
    return 0;
}
