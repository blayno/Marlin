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
 * Blayne Hixson
 */
 #include "../../inc/MarlinConfig.h"
#include "../gcode.h"
#include "../../module/planner.h" 
#include "M877.h"


#if ENABLED (M6_Tool_Change)
 


/**
 * M6 - TOLL
 */
  byte   magaz = 0;                   //  tool in the store
void GcodeSuite::M6() {

   
if (parser.seenval('T')) {
		 
     const byte Ntool = parser.value_byte(); // tool number
	
	 
     if (magaz - Ntool != 0 &&  Ntool>0 &&  Ntool <3 ) {
	 switch (magaz) {
		 
	 case 1:
	      process_subcommands_now(F(MAIN_MENU_ITEM_7_GCODE));  
      SERIAL_ECHOLNPGM("V-1");   //executed when magaz is 1, unload tool 1
      break;
	  
    case 2:
	       process_subcommands_now(F(MAIN_MENU_ITEM_8_GCODE));  
      SERIAL_ECHOLNPGM("V-2");   //executed when magaz is 2, unload tool 2
      break;
	  }
	  
	     switch (Ntool) {
    case 1:
	      process_subcommands_now(T1CODE);  
      SERIAL_ECHOLNPGM("T-1");   //executed when Ntool is 1, load tool 1
	  magaz = 1 ;
      break;
	  
    case 2:
	       process_subcommands_now(F(MAIN_MENU_ITEM_6_GCODE));  
      SERIAL_ECHOLNPGM("T-2");   //executed when Ntool is 2, load tool 2
	  magaz = 2 ;
      break;
    
       }
	 
      }
      else
       { 
        SERIAL_ECHOLNPGM("OK_T"); // THE TOOL DOES NOT NEED TO CHANGE
       }
	   
      return;
 }
  
 }

#endif // M6 TOOL CHANGE