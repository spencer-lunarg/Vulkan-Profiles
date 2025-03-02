/*
 * Copyright (c) 2015-2022 The Khronos Group Inc.
 * Copyright (c) 2015-2022 Valve Corporation
 * Copyright (c) 2015-2022 LunarG, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Authors:
 * - Christophe Riccio <christophe@lunarg.com>
 */

#pragma once

#include <string>
#include <vector>

#include <vulkan/vk_layer.h>
#include <vulkan/vulkan.h>

namespace vku {

typedef std::vector<std::string> Strings;
typedef std::vector<std::pair<std::string, int>> List;
typedef void *(*LAYER_SETTING_LOG_CALLBACK)(const char *setting_key, const char *message);

// Initialize the callback function to get error messages. By default the error messages are outputed to stderr. Use nullptr to
// return to the default behavior.
void InitLayerSettingsLogCallback(LAYER_SETTING_LOG_CALLBACK callback);

// Check whether a setting was set either from vk_layer_settings.txt or an environment variable
bool IsLayerSetting(const char *layer_key, const char *setting_key);

// Query setting data for BOOL setting type in the layer manifest
bool GetLayerSettingBool(const char *layer_key, const char *setting_key);

// Query setting data for INT setting type in the layer manifest
int GetLayerSettingInt(const char *layer_key, const char *setting_key);

// Query setting data for FLOAT setting type in the layer manifest
double GetLayerSettingFloat(const char *layer_key, const char *setting_key);

// Query setting data for FRAMES setting type in the layer manifest
std::string GetLayerSettingFrames(const char *layer_key, const char *setting_key);

// Query setting data for STRING, ENUM, LOAD_FILE, SAVE_FILE and SAVE_FOLDER setting types in the layer manifest
std::string GetLayerSettingString(const char *layer_key, const char *setting_key);

// Query setting data for FLAGS setting type in the layer manifest
Strings GetLayerSettingStrings(const char *layer_key, const char *setting_key);

// Query setting data for LIST setting type in the layer manifest
List GetLayerSettingList(const char *layer_key, const char *setting_key);
}  // namespace vku
