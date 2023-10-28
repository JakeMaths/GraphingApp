#pragma once

/// Necessary Includes.
///
/// .

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <iomanip>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

//! Default Window Width
const float WINDOW_WIDTH = 1920;
//! Default Window Height
const float WINDOW_HEIGHT = 1080;

//! Default Min X Value for Graphing
const float DEFAULT_X_MIN = -10;
//! Default Max X Value for Graphing
const float DEFAULT_X_MAX = 10;
//! Default Min Y Value for Graphing
const float DEFAULT_Y_MIN = -5.625;
//! Default Max Y Value for Graphing
const float DEFAULT_Y_MAX = 5.625;

//! Default Min Width Position for Graphing
const float DEFAULT_W_MIN = 0;
//! Default Max Width Position for Graphing
const float DEFAULT_W_MAX = 1920;
//! Default Min Height Position for Graphing
const float DEFAULT_H_MIN = 0;
//! Default Max Height Position for Graphing
const float DEFAULT_H_MAX = 1080;

//! Default Graph Axis Tick Marker Length in pixels
const int DEFAULT_AXIS_TICK_LENGTH = 10;