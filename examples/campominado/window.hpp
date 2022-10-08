#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "abcgOpenGL.hpp"

class Window : public abcg::OpenGLWindow {
protected:
  void onCreate() override;
  void onPaintUI() override;

private:
  // cores utilizadas botões
  static auto const button_color_default = IM_COL32(100, 100, 100, 255);
  static auto const button_hovered_default = IM_COL32(150, 150, 150, 255);
  static auto const button_zero = IM_COL32(185, 185, 185, 255);
  static auto const button_one = IM_COL32(196, 255, 192, 255);
  static auto const button_two = IM_COL32(255, 255, 132, 255);
  static auto const button_three = IM_COL32(255, 207, 123, 255);
  static auto const button_four = IM_COL32(255, 183, 131, 255);
  static auto const button_five = IM_COL32(255, 95, 95, 255);
  static auto const button_bomb = IM_COL32(255, 28, 28, 255);
  static auto const button_text = IM_COL32(0, 0, 0, 255);

  static int const m_N{8}; // Board size is m_N x m_N

  enum class GameState { Bomb, Flag, Win, Lose };
  GameState m_gameState;
  /*
   * B - o quadrado tem uma boma
   * F - o quadrado está flegado e é uma bomba
   * f - o quadrado está flegafo e não é uma bomba
   * [0...5] - indica quantas bombas estão ao redor do quadrado
   */
  std::array<char, m_N * m_N> m_board{};

  void checkWinCondition();
  void restartGame();
  void clickButton(int i, int j);
  int getNumberBombsInPerimeter(int i, int j);
};

#endif