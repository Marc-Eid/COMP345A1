#include "Belt.h"
#include <vector>
#include <stdexcept> // For std::runtime_error
#include <algorithm> // For std::find

const std::vector<EnhancementType> Belt::allowedEnhancements = {
        EnhancementType::Constitution, EnhancementType::Strength
};

Belt::Belt(const std::string& name, const Enchantment& enchantment) : Item(name, enchantment) {
    if (std::find(allowedEnhancements.begin(), allowedEnhancements.end(), enchantment.type) == allowedEnhancements.end()) {
        throw std::runtime_error("Invalid enchantment type for Belt.");
    }
}

std::string Belt::getType() const {
    return "Belt";
}
