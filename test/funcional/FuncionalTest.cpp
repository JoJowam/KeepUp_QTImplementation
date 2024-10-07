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

    const std::vector<ServiceOrder*>& orders = factory->getAllServiceOrders();
    
    assert(orders.size() == 1);
    
    ServiceOrder* createdOrder = orders.front();

    assert(createdOrder->getOrderName() == "ORDEM 1" && "Error: Order name mismatch.");
    assert(createdOrder->getEquipment() == "MÁQUINA 1" && "Error: Equipment mismatch.");
    assert(createdOrder->getSector() == "SETOR 1" && "Error: Sector mismatch.");
    assert(createdOrder->getPriority() == "ALTA" && "Error: Priority mismatch.");
    assert(createdOrder->getDeadline() == "10/10/2024" && "Error: Deadline mismatch.");
    assert(createdOrder->getOrderType() == "CORRETIVA" && "Error: Order type mismatch.");
    assert(createdOrder->getErrorDescription() == "NECESSÁRIO ATUALIZAÇÃO DE SOFTWARE" && "Error: Error description mismatch.");

    std::cout << "TEST: Service order creation and listing successful!" << std::endl;

    factory->destroyServiceOrder(serviceOrder);
    FactoryImpl::destroyInstance();
}

void test_deleteServiceOrder() {
    Factory* factory = FactoryImpl::getInstance();

    ServiceOrder* serviceOrder = factory->createServiceOrder(
        "ORDEM 1", "MÁQUINA 1", "SETOR 1", "ALTA", "10/10/2024", "CORRETIVA", "NECESSÁRIO ATUALIZAÇÃO DE SOFTWARE"
    );

    assert(factory->getAllServiceOrders().size() == 1);

    bool deletionResult = factory->destroyServiceOrder(serviceOrder);
    assert(deletionResult);

    assert(factory->getAllServiceOrders().empty());

    std::cout << "TEST: Service order deletion successful!" << std::endl;

    FactoryImpl::destroyInstance();
}

void test_dispatchServiceOrder() {
    Factory* factory = FactoryImpl::getInstance();

    ServiceOrder* serviceOrder = factory->createServiceOrder(
        "ORDEM 1", "MÁQUINA 1", "SETOR 1", "ALTA", "10/10/2024", "CORRETIVA", "NECESSÁRIO ATUALIZAÇÃO DE SOFTWARE"
    );

    bool dispatchResult = factory->setServiceOrderPosted(serviceOrder);
    assert(dispatchResult);

    assert(serviceOrder->getPostedOrderState());

    std::cout << "TEST: Service order dispatch successful!" << std::endl;

    factory->destroyServiceOrder(serviceOrder);
    FactoryImpl::destroyInstance();
}

void test_listAllServiceOrders() {
    Factory* factory = FactoryImpl::getInstance();

    ServiceOrder* serviceOrder1 = factory->createServiceOrder(
        "ORDEM 1", "MÁQUINA 1", "SETOR 1", "ALTA", "10/10/2024", "CORRETIVA", "NECESSÁRIO ATUALIZAÇÃO DE SOFTWARE"
    );
    ServiceOrder* serviceOrder2 = factory->createServiceOrder(
        "ORDEM 2", "MÁQUINA 2", "SETOR 2", "MÉDIA", "15/10/2024", "PREVENTIVA", "VERIFICAÇÃO DE SISTEMAS"
    );
    ServiceOrder* serviceOrder3 = factory->createServiceOrder(
        "ORDEM 3", "MÁQUINA 3", "SETOR 3", "BAIXA", "20/10/2024", "CORRETIVA", "SUBSTITUIÇÃO DE PEÇAS"
    );

    const std::vector<ServiceOrder*>& orders = factory->getAllServiceOrders();

    assert(orders.size() == 3 && "Error: Incorrect number of service orders.");

    ServiceOrder* createdOrder1 = orders.at(0);
    assert(createdOrder1->getOrderName() == "ORDEM 1" && "Error: Order 1 name mismatch.");
    assert(createdOrder1->getEquipment() == "MÁQUINA 1" && "Error: Order 1 equipment mismatch.");

    ServiceOrder* createdOrder2 = orders.at(1);
    assert(createdOrder2->getOrderName() == "ORDEM 2" && "Error: Order 2 name mismatch.");
    assert(createdOrder2->getEquipment() == "MÁQUINA 2" && "Error: Order 2 equipment mismatch.");

    ServiceOrder* createdOrder3 = orders.at(2);
    assert(createdOrder3->getOrderName() == "ORDEM 3" && "Error: Order 3 name mismatch.");
    assert(createdOrder3->getEquipment() == "MÁQUINA 3" && "Error: Order 3 equipment mismatch.");

    std::cout << "TEST: Listing all service orders successful!" << std::endl;

    factory->destroyServiceOrder(serviceOrder1);
    factory->destroyServiceOrder(serviceOrder2);
    factory->destroyServiceOrder(serviceOrder3);

    FactoryImpl::destroyInstance();
}


int main() {
    test_createServiceOrder();
    test_deleteServiceOrder();
    test_dispatchServiceOrder();
    test_listAllServiceOrders();
    
    return 0;
}
