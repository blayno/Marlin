 /**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 *Blayne Hixson 
 */
 #include "../../inc/MarlinConfig.h"
#include "../gcode.h"
#include "../../module/planner.h" 

#if ENABLED (M6_Tool_Change)

static char* T1CODE = (char*) "M280 P1 S0\nG4 S2\nG90\nG1 X 87 F2000\nG1 Z 230 F2000\nG1 Z 245 F500\nG1 X 106 F2000\nG1 Z 10 F2000\nG4 S2\nM400\nM280 P1 S43\nG4 S2";

#endif //M6 TOOL CHANGE



