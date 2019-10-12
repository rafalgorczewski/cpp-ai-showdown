#include <fstream>

#include "archer.hpp"
#include "bomberman.hpp"
#include "knight.hpp"
#include "mapparser.hpp"

namespace eape {

  MapParser::MapParser(const std::string& path) : m_map_path(path) {
  }

  MapParsedEntities MapParser::parse_map() const {
    Map map;
    std::vector<std::shared_ptr<Unit>> lhs_units;
    std::vector<std::shared_ptr<Unit>> rhs_units;

    std::ifstream map_stream(m_map_path);
    std::string map_row;

    for (auto y = 0; std::getline(map_stream, map_row); ++y) {
      map.add_row(map_row.size());

      for (auto x = 0; auto tile_char : map_row) {
        switch (tile_char) {
          default:
            [[fallthrough]];
          case '.': {
            map[x][y] = Tile::Floor;
            break;
          }
          case '=': {
            map[x][y] = Tile::Water;
            break;
          }
          case '#': {
            map[x][y] = Tile::Wall;
            break;
          }
          case 'a':
            [[fallthrough]];
          case 'b': {
            lhs_units.push_back(std::make_shared<Knight>());
            break;
          }
          case 'c':
            [[fallthrough]];
          case 'd': {
            lhs_units.push_back(std::make_shared<Archer>());
            break;
          }
          case 'e':
            [[fallthrough]];
          case 'f': {
            lhs_units.push_back(std::make_shared<Bomberman>());
            break;
          }
          case 'g':
            [[fallthrough]];
          case 'h': {
            rhs_units.push_back(std::make_shared<Knight>());
            break;
          }
          case 'i':
            [[fallthrough]];
          case 'j': {
            rhs_units.push_back(std::make_shared<Archer>());
            break;
          }
          case 'k':
            [[fallthrough]];
          case 'l': {
            rhs_units.push_back(std::make_shared<Bomberman>());
            break;
          }
        }
        ++x;
      }
    }
    return { std::move(map), { std::move(lhs_units), std::move(rhs_units) } };
  }

}  // namespace eape