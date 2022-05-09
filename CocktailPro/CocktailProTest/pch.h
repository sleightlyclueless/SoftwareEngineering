#pragma once

#include <sstream>
#include <climits>

#define protected public
#define private public
#include "gtest/gtest.h"

#include "../CocktailPro/CocktailPro.h"
#include "../CocktailPro/CocktailZubereiter.h"
#include "../CocktailPro/DeviceVerwalter.h"
#include "../CocktailPro/Dosierer.h"
#include "../CocktailPro/Entleerer.h"
#include "../CocktailPro/InternalDevice.h"
#include "../CocktailPro/MischbaresRezeptbuch.h"
#include "../CocktailPro/Mixer.h"
#include "../CocktailPro/Observer.h"
#include "../CocktailPro/Recipe.h"
#include "../CocktailPro/RecipeBook.h"
#include "../CocktailPro/RecipeStep.h"
#include "../CocktailPro/Schuettler.h"
#include "../CocktailPro/Stampfer.h"
#include "../CocktailPro/Subject.h"
#include "../CocktailPro/Timer.h"
#include "../CocktailPro/VorhandeneZutaten.h"
#include "../CocktailPro/Waage.h"
#undef protected
#undef private