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
# include <random>
# include <array>
# include "Fwd.hpp"
# include "SFMT.hpp"

namespace s3d
{
	/// <summary>
	/// 乱数生成エンジン MT 11213b (周期 2^11213-1, メモリ消費 2,816 bytes)
	/// </summary>
	class MT11213b
	{
	private:

		using engine_type = std::mersenne_twister_engine<unsigned, 32, 351, 175, 19, 0xccab8ee7,
			11, 0xffffffff, 7, 0x31b6ab00, 15, 0xffe50000, 17, 1812433253>;

		engine_type m_engine;

	public:

		using result_type = engine_type::result_type;

		/// <summary>
		/// デフォルトコンストラクタ
		/// </summary>
		/// <remarks>
		/// シードはランダムに設定されます。
		/// </remarks>
		MT11213b();

		/// <summary>
		/// シードを指定して乱数生成器を作成します。
		/// </summary>
		/// <param name="seed">
		/// シード
		/// </param>
		explicit MT11213b(uint32 seed);

		/// <summary>
		/// シードを指定して乱数生成器を作成します。
		/// </summary>
		/// <param name="seeds">
		/// シード
		/// </param>
		explicit MT11213b(const std::array<uint32, 8>& seeds);

		/// <summary>
		/// シードを設定しなおします。
		/// </summary>
		/// <param name="seed">
		/// シード
		/// </param>
		/// <returns>
		/// なし
		/// </returns>
		void seed(const uint32 seed);

		/// <summary>
		/// シードを設定しなおします。
		/// </summary>
		/// <param name="seeds">
		/// シード
		/// </param>
		/// <returns>
		/// なし
		/// </returns>
		void seed(const std::array<uint32, 8>& seeds);

		/// <summary>
		/// 生成される乱数の最小値を返します。
		/// </summary>
		/// <returns>
		/// 生成される乱数の最小値
		/// </returns>
		[[nodiscard]] static constexpr result_type min()
		{
			return engine_type::min();
		}

		/// <summary>
		/// 生成される乱数の最大値を返します。
		/// </summary>
		/// <returns>
		/// 生成される乱数の最大値
		/// </returns>
		[[nodiscard]] static constexpr result_type max()
		{
			return engine_type::max();
		}

		/// <summary>
		/// 乱数を生成します。
		/// </summary>
		/// <returns>
		/// 乱数
		/// </returns>
		result_type operator()()
		{
			return m_engine();
		}

		/// <summary>
		/// [0, 1) の範囲の乱数を生成します。
		/// </summary>
		/// <returns>
		/// [0, 1) の範囲の乱数
		/// </returns>
		double generateReal()
		{
			const uint32 a = m_engine();
			const uint32 b = m_engine();
			return sfmt::sfmt_to_res53_mix(a, b);
		}

		[[nodiscard]] std::string serialize() const;

		void deserialize(const std::string& representation);
	};

	/// <summary>
	/// 乱数生成エンジン MT 19937 (周期 2^19937-1, メモリ消費 5,000 bytes)
	/// </summary>
	class MT19937
	{
	private:

		using engine_type = std::mt19937;

		engine_type m_engine;

	public:

		using result_type = engine_type::result_type;

		/// <summary>
		/// デフォルトコンストラクタ
		/// </summary>
		/// <remarks>
		/// シードはランダムに設定されます。
		/// </remarks>
		MT19937();

		/// <summary>
		/// シードを指定して乱数生成器を作成します。
		/// </summary>
		/// <param name="seed">
		/// シード
		/// </param>
		explicit MT19937(uint32 seed);

		/// <summary>
		/// シードを指定して乱数生成器を作成します。
		/// </summary>
		/// <param name="seeds">
		/// シード
		/// </param>
		explicit MT19937(const std::array<uint32, 8>& seeds);

		/// <summary>
		/// シードを設定しなおします。
		/// </summary>
		/// <param name="seed">
		/// シード
		/// </param>
		/// <returns>
		/// なし
		/// </returns>
		void seed(const uint32 seed);

		/// <summary>
		/// シードを設定しなおします。
		/// </summary>
		/// <param name="seeds">
		/// シード
		/// </param>
		/// <returns>
		/// なし
		/// </returns>
		void seed(const std::array<uint32, 8>& seeds);

		/// <summary>
		/// 生成される乱数の最小値を返します。
		/// </summary>
		/// <returns>
		/// 生成される乱数の最小値
		/// </returns>
		[[nodiscard]] static constexpr result_type min()
		{
			return engine_type::min();
		}

		/// <summary>
		/// 生成される乱数の最大値を返します。
		/// </summary>
		/// <returns>
		/// 生成される乱数の最大値
		/// </returns>
		[[nodiscard]] static constexpr result_type max()
		{
			return engine_type::max();
		}

		/// <summary>
		/// 乱数を生成します。
		/// </summary>
		/// <returns>
		/// 乱数
		/// </returns>
		result_type operator()()
		{
			return m_engine();
		}

		/// <summary>
		/// [0, 1) の範囲の乱数を生成します。
		/// </summary>
		/// <returns>
		/// [0, 1) の範囲の乱数
		/// </returns>
		double generateReal()
		{
			const uint32 a = m_engine();
			const uint32 b = m_engine();
			return sfmt::sfmt_to_res53_mix(a, b);
		}

		[[nodiscard]] std::string serialize() const;

		void deserialize(const std::string& representation);
	};

	/// <summary>
	/// 乱数生成エンジン MT 19937-64 (周期 2^19937-1, メモリ消費 5,008 bytes)
	/// </summary>
	class MT19937_64
	{
	private:

		using engine_type = std::mt19937_64;

		engine_type m_engine;

	public:

		using result_type = engine_type::result_type;

		/// <summary>
		/// デフォルトコンストラクタ
		/// </summary>
		/// <remarks>
		/// シードはランダムに設定されます。
		/// </remarks>
		MT19937_64();

		/// <summary>
		/// シードを指定して乱数生成器を作成します。
		/// </summary>
		/// <param name="seed">
		/// シード
		/// </param>
		explicit MT19937_64(const uint64 seed);

		/// <summary>
		/// シードを指定して乱数生成器を作成します。
		/// </summary>
		/// <param name="seeds">
		/// シード
		/// </param>
		explicit MT19937_64(const std::array<uint64, 8>& seeds);

		/// <summary>
		/// シードを設定しなおします。
		/// </summary>
		/// <param name="seed">
		/// シード
		/// </param>
		/// <returns>
		/// なし
		/// </returns>
		void seed(uint64 seed);

		/// <summary>
		/// シードを設定しなおします。
		/// </summary>
		/// <param name="seeds">
		/// シード
		/// </param>
		/// <returns>
		/// なし
		/// </returns>
		void seed(const std::array<uint64, 8>& seeds);

		/// <summary>
		/// 生成される乱数の最小値を返します。
		/// </summary>
		/// <returns>
		/// 生成される乱数の最小値
		/// </returns>
		[[nodiscard]] static constexpr result_type min()
		{
			return engine_type::min();
		}

		/// <summary>
		/// 生成される乱数の最大値を返します。
		/// </summary>
		/// <returns>
		/// 生成される乱数の最大値
		/// </returns>
		[[nodiscard]] static constexpr result_type max()
		{
			return engine_type::max();
		}

		/// <summary>
		/// 乱数を生成します。
		/// </summary>
		/// <returns>
		/// 乱数
		/// </returns>
		result_type operator()()
		{
			return m_engine();
		}

		/// <summary>
		/// [0, 1) の範囲の乱数を生成します。
		/// </summary>
		/// <returns>
		/// [0, 1) の範囲の乱数
		/// </returns>
		double generateReal()
		{
			return sfmt::sfmt_to_res53(m_engine());
		}

		[[nodiscard]] std::string serialize() const;

		void deserialize(const std::string& representation);
	};
}
