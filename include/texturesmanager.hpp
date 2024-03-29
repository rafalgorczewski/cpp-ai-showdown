#ifndef EAPE_TEXTURESMANAGER_HPP
#define EAPE_TEXTURESMANAGER_HPP

#include <string>
#include <unordered_map>

#include <SFML/Graphics.hpp>

namespace eape {

  class TexturesManager {
   public:
    void load();

    sf::Texture& operator[](const std::string& name) &;
    const sf::Texture& operator[](const std::string& name) const&& = delete;

   private:
    std::unordered_map<std::string, sf::Texture> m_textures;
  };

}  // namespace eape

#endif  // EAPE_TEXTURESMANAGER_HPP
