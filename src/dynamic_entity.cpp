#include "sensor_utils/dynamic_entity.h"

namespace sensor_utils {
DynamicEntity::DynamicEntity() : position(0, 0), viewDirection(1, 0),
    velocity(0), moveDirection(1, 0), lastPositon(0, 0), lastVelocity(0) {}

void DynamicEntity::updatePosition(const lms::math::vertex2f &position,
                                   const lms::math::vertex2f &viewDirection) {
    this->lastPositon = this->position;
    this->position = position;
    this->viewDirection = viewDirection;
}

void DynamicEntity::updateVelocity(float velocity,
                    const lms::math::vertex2f &moveDirection) {
    this->lastVelocity = this->velocity;
    this->velocity = velocity;
    this->moveDirection = moveDirection;
}

float DynamicEntity::movedDistance() const {
    return this->position.distance(this->lastPositon);
}

float DynamicEntity::deltaVelocity() const {
    return this->velocity - this->lastVelocity;
}
}//sensor_utils
