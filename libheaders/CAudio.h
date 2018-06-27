#pragma once
#include <string>
#include <vector>

namespace SV_ASSIST
{
	namespace AUDIO
	{
		void Exec();

		void UpdateData();

		const std::vector<std::wstring>& GetInputAudio();

		const std::vector<std::wstring>& GetOutputAudio();
	}
}