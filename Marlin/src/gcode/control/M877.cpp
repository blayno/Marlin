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
#include "M877.h"  




/**
 * M877 update M6 tool change position gcode
 */
 #if ENABLED (M6_Tool_Change)


 void GcodeSuite::M877() {

  static char* i = (char*) " ";


   // Assume no errors
  bool ok = true;

  

   // No parameters? Show current state.
  if (!parser.seenval('S')) return M877_report();


   
  if (parser.seenval('S')){
    i = parser.value_string();
    //T1CODE = i;
    //SERIAL_ECHOLNPGM_P("M877 Updated",":",T1CODE);
   
    

  }

   // Save the new offsets
  if (ok) T1CODE = i;
    SERIAL_ECHOLNPGM_P("M877 Updated",":",T1CODE);
    
   




 }
   


void GcodeSuite::M877_report(const bool forReplay/*=true*/) {
  SERIAL_ECHOPGM_P("M877 Report",":",T1CODE,":");
}





 


#endif //M6_Tool_Change
