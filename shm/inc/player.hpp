#pragma once

#include <memory>

#include "cargoHolder.hpp"
#include "ship.hpp"

class Player : public CargoHolder /* through its ship */ {
public:
    Player(Ship& ship, size_t money, size_t availableSpace);

    std::unique_ptr<Ship> getShip() { return std::move(ship_); }
    size_t getMoney() const { return money_; }
    size_t getavailableSpace() const { return availableSpace_; }
    size_t getSpeed() const { return ship_->getSpeed(); }
    std::shared_ptr<Cargo> getCargo(size_t index) const { return ship_->getCargo(index); }

    void changeMoney(size_t amount);
    void clearEmptyCargo() { ship_->clearEmptyCargo(); };

    /* override from CargoHolder through its ship */
    void receiveCargo(Cargo* cargo, size_t amount, CargoHolder* cargoHolder) override { ship_->receiveCargo(cargo, amount, cargoHolder); }
    void clearEmptyCargos() override { ship_->clearEmptyCargos(); }

private:
    size_t getAvailableSpace() { return ship_->getAvailableSpace(); }

    std::unique_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;
};
