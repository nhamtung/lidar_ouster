// Copyright 2020, Steve Macenski
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ROS2_OUSTER__IMAGE_OS_HPP_
#define ROS2_OUSTER__IMAGE_OS_HPP_

namespace picture_os
{

/**
 * @struct image_os::ImageOS
 * @brief The image structure to hold the information for
 * publishing in ROS2.
 */
struct EIGEN_ALIGN16 ImageOS
{
  float intensity;
  uint16_t reflectivity;
  uint16_t noise;
  uint32_t range;
  uint8_t ring;
  uint8_t col;
  //EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  /**
   * @brief A factory to create the structure given a set of information
   * @param x position in m
   * @param y position in m
   * @param z position in m
   * @param intensity Intensity value from reading
   * @param t time in ns
   * @param reflectivity Reflectivity value from reading
   * @param ring The ring ID the measurement came from
   * @param column The column of the reading in the ring
   * @param noise Noise value from reading
   * @param range Range value from reading
   */
  static inline ImageOS make(
    float x, float y, float z, float intensity,
    uint32_t t, uint16_t reflectivity, uint8_t ring, uint8_t col,
    uint16_t noise, uint32_t range)
  {
    return {intensity, reflectivity, noise, range, ring, col};
  }
};

}  // namespace image_os

#endif  // ROS2_OUSTER__IMAGE_OS_HPP_
