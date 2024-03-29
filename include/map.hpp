#ifndef EAPE_MAP_HPP
#define EAPE_MAP_HPP

#include <cstddef>
#include <optional>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include "state.pb.h"

#include "texturesmanager.hpp"

namespace eape {

  enum class Tile { Floor, Water, Wall };

  class Map {
   public:
    std::vector<Tile>& operator[](std::size_t x) &;
    const std::vector<Tile>& operator[](std::size_t x) const&;
    const std::vector<Tile>& operator[](std::size_t x) const&& = delete;

    void add_row(std::size_t size);

    bool is_tile_passable(sf::Vector2i position) const;

    std::vector<sf::Sprite>& get_sprites(TexturesManager& textures_manager) &;
    const std::vector<sf::Sprite>& get_sprites() const&& = delete;

    sf::Vector2i get_size() const;

    // Serialize size and tiles only
    eap::Map serialize_partially() const;

   private:
    void generate_sprites(TexturesManager& textures_manager);

   private:
    std::vector<std::vector<Tile>> m_tiles;
    std::optional<std::vector<sf::Sprite>> m_sprites;
  };

}  // namespace eape

#endif  // EAPE_MAP_HPP
