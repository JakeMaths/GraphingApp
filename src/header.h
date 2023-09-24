#pragma once

/// Necessary Includes.
///
/// .

#include <iostream>
#include <vector>
#include <ctime>

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
const float DEFAULT_X_MIN = -2;
//! Default Max X Value for Graphing
const float DEFAULT_X_MAX = 2;
//! Default Min Y Value for Graphing
const float DEFAULT_Y_MIN = -2;
//! Default Max Y Value for Graphing
const float DEFAULT_Y_MAX = 2;

//! Default Min Width Position for Graphing
const float DEFAULT_W_MIN = 760;
//! Default Max Width Position for Graphing
const float DEFAULT_W_MAX = 1560;
//! Default Min Height Position for Graphing
const float DEFAULT_H_MIN = 140;
//! Default Max Height Position for Graphing
const float DEFAULT_H_MAX = 940;

//! Default Zero Threshold, values below are zero
const float DEFAULT_ZERO_THRESH = 0.01f;