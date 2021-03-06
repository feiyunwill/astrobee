/* Copyright (c) 2017, United States Government, as represented by the
 * Administrator of the National Aeronautics and Space Administration.
 *
 * All rights reserved.
 *
 * The Astrobee platform is licensed under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with the
 * License. You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 * Based off libsurvive: https://github.com/cnlohr/libsurvive
 */

#include "vive_data_imu.h"

void vive_data_imu(tracker_t const * tracker,
  uint32_t timecode, int16_t acc[3], int16_t gyr[3]) {
  imu_t event;
  event.timestamp = timecode;
  memcpy(event.acc, acc, sizeof(int16_t[3]));
  memcpy(event.gyr, gyr, sizeof(int16_t[3]));
  // Simple passthrough
  if (tracker->driver->imu_cb)
    tracker->driver->imu_cb(tracker, &event);
}
