#include "UnitServiceOrder.hpp"
#include "../../src/ServiceOrderImpl.hpp"

#include <cassert>
#include <iostream>

void UnitServiceOrder::runUnitTests() {
    assert(unit_testSetAndGetOrderName());
    assert(unit_testSetAndGetEquipment());
    assert(unit_testSetAndGetSector());
    assert(unit_testSetAndGetPriority());
    assert(unit_testSetAndGetDeadline());
    assert(unit_testSetAndGetOrderType());
    assert(unit_testSetAndGetErrorDescription());
    assert(unit_testSetAndGetPostedState());
}

bool UnitServiceOrder::unit_testSetAndGetOrderName() {
    ServiceOrderImpl serviceOrder("ORDEM 1", "Equipamento 1", "Setor 1", "Alta", "2024-10-10", "Corretiva", "Descrição de Erro");
    serviceOrder.setOrderName("ORDEM ALTERADA");
    assert(serviceOrder.getOrderName() == "ORDEM ALTERADA");

    std::cout << "TEST: ServiceOrderImpl::setOrderName() and getOrderName() passed.\n";
    return true;
}

bool UnitServiceOrder::unit_testSetAndGetEquipment() {
    ServiceOrderImpl serviceOrder("ORDEM 1", "Equipamento 1", "Setor 1", "Alta", "2024-10-10", "Corretiva", "Descrição de Erro");
    serviceOrder.setEquipment("Equipamento Alterado");
    assert(serviceOrder.getEquipment() == "Equipamento Alterado");

    std::cout << "TEST: ServiceOrderImpl::setEquipment() and getEquipment() passed.\n";
    return true;
}

bool UnitServiceOrder::unit_testSetAndGetSector() {
    ServiceOrderImpl serviceOrder("ORDEM 1", "Equipamento 1", "Setor 1", "Alta", "2024-10-10", "Corretiva", "Descrição de Erro");
    serviceOrder.setSector("Setor Alterado");
    assert(serviceOrder.getSector() == "Setor Alterado");

    std::cout << "TEST: ServiceOrderImpl::setSector() and getSector() passed.\n";
    return true;
}

bool UnitServiceOrder::unit_testSetAndGetPriority() {
    ServiceOrderImpl serviceOrder("ORDEM 1", "Equipamento 1", "Setor 1", "Alta", "2024-10-10", "Corretiva", "Descrição de Erro");
    serviceOrder.setPriority("Baixa");
    assert(serviceOrder.getPriority() == "Baixa");

    std::cout << "TEST: ServiceOrderImpl::setPriority() and getPriority() passed.\n";
    return true;
}

bool UnitServiceOrder::unit_testSetAndGetDeadline() {
    ServiceOrderImpl serviceOrder("ORDEM 1", "Equipamento 1", "Setor 1", "Alta", "2024-10-10", "Corretiva", "Descrição de Erro");
    serviceOrder.setDeadline("2024-12-12");
    assert(serviceOrder.getDeadline() == "2024-12-12");

    std::cout << "TEST: ServiceOrderImpl::setDeadline() and getDeadline() passed.\n";
    return true;
}

bool UnitServiceOrder::unit_testSetAndGetOrderType() {
    ServiceOrderImpl serviceOrder("ORDEM 1", "Equipamento 1", "Setor 1", "Alta", "2024-10-10", "Corretiva", "Descrição de Erro");
    serviceOrder.setOrderType("Preventiva");
    assert(serviceOrder.getOrderType() == "Preventiva");

    std::cout << "TEST: ServiceOrderImpl::setOrderType() and getOrderType() passed.\n";
    return true;
}

bool UnitServiceOrder::unit_testSetAndGetErrorDescription() {
    ServiceOrderImpl serviceOrder("ORDEM 1", "Equipamento 1", "Setor 1", "Alta", "2024-10-10", "Corretiva", "Descrição de Erro");
    serviceOrder.setErrorDescription("Erro Alterado");
    assert(serviceOrder.getErrorDescription() == "Erro Alterado");

    std::cout << "TEST: ServiceOrderImpl::setErrorDescription() and getErrorDescription() passed.\n";
    return true;
}

bool UnitServiceOrder::unit_testSetAndGetPostedState() {
    ServiceOrderImpl serviceOrder("ORDEM 1", "Equipamento 1", "Setor 1", "Alta", "2024-10-10", "Corretiva", "Descrição de Erro");
    serviceOrder.setPostedOrderState(true);
    assert(serviceOrder.getPostedOrderState());

    std::cout << "TEST: ServiceOrderImpl::setPostedOrderState() and getPostedOrderState() passed.\n";
    return true;
}