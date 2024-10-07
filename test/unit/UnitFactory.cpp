#include "UnitFactory.hpp"
#include "../../src/FactoryImpl.hpp"
#include "../../src/ServiceOrderImpl.hpp"

#include <cassert>
#include <iostream>

void UnitFactory::runUnitTests() {
    assert(unit_testSingletonInstance());
    assert(unit_testCreateServiceOrder());
    assert(unit_testDestroyServiceOrder());
    assert(unit_testGetAllServiceOrders());
    assert(unit_testSetServiceOrderPosted());
    assert(unit_testDestroyInstance());
}

bool UnitFactory::unit_testSingletonInstance() {
    FactoryImpl* factory1 = FactoryImpl::getInstance();
    FactoryImpl* factory2 = FactoryImpl::getInstance();

    assert(factory1 == factory2 && "Singleton instance test failed: Different instances.");

    std::cout << "TEST: FactoryImpl::getInstance() passed.\n";
    return true;
}

bool UnitFactory::unit_testCreateServiceOrder() {
    FactoryImpl* factory = FactoryImpl::getInstance();

    // Criando manualmente um ServiceOrderImpl e adicionando diretamente ao array
    ServiceOrderImpl* serviceOrder = new ServiceOrderImpl(
        "ORDEM 1", "Equipamento 1", "Setor 1", "Alta", "2024-10-10", "Corretiva", "Descrição de Erro"
    );
    factory->serviceOrders.push_back(serviceOrder);

    // Validando o conteúdo da ordem de serviço adicionada
    assert(serviceOrder->getOrderName() == "ORDEM 1");
    assert(serviceOrder->getEquipment() == "Equipamento 1");

    std::cout << "TEST: FactoryImpl::createServiceOrder() (manual population) passed.\n";

    factory->destroyServiceOrder(serviceOrder);
    return true;
}

bool UnitFactory::unit_testDestroyServiceOrder() {
    FactoryImpl* factory = FactoryImpl::getInstance();

    // Adicionando diretamente uma ordem de serviço no array
    ServiceOrderImpl* serviceOrder = new ServiceOrderImpl(
        "ORDEM 2", "Equipamento 2", "Setor 2", "Baixa", "2024-12-12", "Preventiva", "Outro erro"
    );
    factory->serviceOrders.push_back(serviceOrder);

    bool destroyed = factory->destroyServiceOrder(serviceOrder);
    assert(destroyed && "ServiceOrder destruction failed.");
    assert(factory->serviceOrders.empty() && "ServiceOrder list not empty after destruction.");

    std::cout << "TEST: FactoryImpl::destroyServiceOrder() (manual population) passed.\n";
    return true;
}

bool UnitFactory::unit_testGetAllServiceOrders() {
    FactoryImpl* factory = FactoryImpl::getInstance();

    // Adicionando duas ordens diretamente no array
    ServiceOrderImpl* serviceOrder1 = new ServiceOrderImpl(
        "ORDEM 1", "Equipamento 1", "Setor 1", "Alta", "2024-10-10", "Corretiva", "Descrição de Erro"
    );
    ServiceOrderImpl* serviceOrder2 = new ServiceOrderImpl(
        "ORDEM 2", "Equipamento 2", "Setor 2", "Baixa", "2024-12-12", "Preventiva", "Outro erro"
    );
    factory->serviceOrders.push_back(serviceOrder1);
    factory->serviceOrders.push_back(serviceOrder2);

    const std::vector<ServiceOrder*>& orders = factory->getAllServiceOrders();
    assert(orders.size() == 2 && "Incorrect number of service orders.");

    std::cout << "TEST: FactoryImpl::getAllServiceOrders() (manual population) passed.\n";

    factory->destroyServiceOrder(serviceOrder1);
    factory->destroyServiceOrder(serviceOrder2);
    return true;
}

bool UnitFactory::unit_testSetServiceOrderPosted() {
    FactoryImpl* factory = FactoryImpl::getInstance();

    // Adicionando diretamente uma ordem de serviço no array
    ServiceOrderImpl* serviceOrder = new ServiceOrderImpl(
        "ORDEM 3", "Equipamento 3", "Setor 3", "Média", "2024-11-11", "Corretiva", "Erro teste"
    );
    factory->serviceOrders.push_back(serviceOrder);

    bool posted = factory->setServiceOrderPosted(serviceOrder);
    assert(posted && "Failed to set service order as posted.");
    assert(serviceOrder->getPostedOrderState() && "Service order posted state not set correctly.");

    std::cout << "TEST: FactoryImpl::setServiceOrderPosted() (manual population) passed.\n";

    factory->destroyServiceOrder(serviceOrder);
    return true;
}

bool UnitFactory::unit_testDestroyInstance() {
    bool destroyed = FactoryImpl::destroyInstance();
    assert(destroyed && "Failed to destroy the singleton instance.");
    assert(FactoryImpl::getInstance() != nullptr && "Singleton instance not recreated.");

    std::cout << "TEST: FactoryImpl::destroyInstance() passed.\n";
    return true;
}
