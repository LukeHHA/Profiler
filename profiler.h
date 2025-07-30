#pragma once

/**
 * @include <chrono>
 * @include <thread>
 * @include <fstream>
 */

#include <chrono>
#include <thread>

namespace dev
{
	using namespace std::literals;

	/**
	 * @class Profiler
	 * @brief Tracks duration of the life time of the profiler
	 * In which ever scope the profiler is created, it will track the duration it
	 * took from initialization to destruction and write that out to a JSON file.
	 */
	class Profiler
	{
	public:
		Profiler()
		{
			OnAttach();
		}

		~Profiler()
		{
			OnDetach();
		}

		void OnAttach()
		{
			m_StartTime = std::chrono::high_resolution_clock::now();
		}
		void OnDetach()
		{
			m_EndTime = std::chrono::high_resolution_clock::now();
			m_Duration = std::chrono::duration_cast<std::chrono::milliseconds>(m_EndTime - m_StartTime);
		}

	private:
		std::chrono::time_point<std::chrono::steady_clock> m_StartTime;
		std::chrono::time_point<std::chrono::steady_clock> m_EndTime;
		std::chrono::microseconds m_Duration;
	};

	class JSONWriter
	{
	public:
		JSONWriter()
		{
			OnAttach();
		}

		~JSONWriter()
		{
			OnDetach();
		}

		void OnAttach()
		{
				}

		void OnDetach()
		{
		}

	private:
	};
} /// @namespace dev