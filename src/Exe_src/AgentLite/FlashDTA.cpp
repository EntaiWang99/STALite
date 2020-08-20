﻿//  Portions Copyright 2019
// Xuesong Zhou
//   If you help write or modify the code, please also list your names here.
//   The reason of having Copyright info here is to ensure all the modified version, as a whole, under the GPL
//   and further prevent a violation of the GPL.

// More about "How to use GNU licenses for your own software"
// http://www.gnu.org/licenses/gpl-howto.html

#include "stdafx.h"

#include "..\AgentLite\main_api.cpp";
#include "..\AgentLite\signal_api.cpp";


int main(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int iteration_number = 2;
	int column_updating_iterations = 0;

	int signal_updating_iterations = 0;

	int signal_updating_output = 0;

	int assignment_mode = 0;

	CCSVParser parser_settings;

	if (parser_settings.OpenCSVFile("settings.csv", true))
	{

		while (parser_settings.ReadRecord())
		{
			string field;
			int value_int;

			parser_settings.GetValueByFieldName("field", field);
			parser_settings.GetValueByFieldName("value", value_int);

			if (field == "number_of_iterations")
				iteration_number = value_int;

			if (field == "assignment_mode")
				assignment_mode = value_int;

			if (field == "column_updating_iterations")
				column_updating_iterations = value_int;

			if (field == "signal_updating_iterations")
				signal_updating_iterations = value_int;

			if (field == "signal_updating_output")
				signal_updating_output = value_int;

		}
	}

	network_assignment(iteration_number, assignment_mode, column_updating_iterations, 1);  // obtain initial flow values
	SignalAPI(iteration_number, assignment_mode, signal_updating_output);

	//for(int si = 0; si < signal_updating_iterations; si++)
	//{ 
	//	cout << "_______Signal timing iteration No." << si << "_______" << endl;
	//SignalAPI(iteration_number, assignment_mode, signal_updating_output);
	//network_assignment(iteration_number, assignment_mode, column_updating_iterations, 0);  // do not re-load network and demand
	//}



}
