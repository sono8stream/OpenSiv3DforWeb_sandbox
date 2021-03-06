//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2019 Ryo Suzuki
//	Copyright (c) 2016-2019 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# pragma once
# include "Fwd.hpp"
# include "Time.hpp"
# include "Logger.hpp"
# include "Print.hpp"

namespace s3d
{
	/// <summary>
	/// マイクロ秒カウンター
	/// </summary>
	/// <remarks>
	/// 経過時間をマイクロ秒で計測します。
	/// </remarks>
	class MicrosecClock
	{
	private:

		const uint64 m_start = Time::GetMicrosec();

	public:

		/// <summary>
		/// 経過時間（マイクロ秒）
		/// </summary>
		[[nodiscard]] uint64 us() const
		{
			return Time::GetMicrosec() - m_start;
		}

		/// <summary>
		/// ログに経過時間を出力します。
		/// </summary>
		/// <returns>
		/// なし
		/// </returns>
		void log() const { Logger(us(), U"us"_sv); }

		/// <summary>
		/// 経過時間をデバッグ表示します。
		/// </summary>
		/// <returns>
		/// なし
		/// </returns>
		void print() const { Print(us(), U"us"_sv); }
	};
}
