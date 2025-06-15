/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_theme.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 07:40:27 by kyanagis          #+#    #+#             */
/*   Updated: 2025/06/16 07:40:28 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef COLOR_THEME_H
// # define COLOR_THEME_H

// /* ── 輝度調整 ─────────────────────────── */
// # define BR_ADD 0.2   /* 最低輝度（全体の明るさ下限）   */
// # define BR_GAIN 0.2  /* 明るさの伸び幅（大きいほど派手）*/
// # define POW_EXP 0.30 /* prog^EXP：中心へ行くほど明るい */

// /* ── ストライプ＆彩度 ──────────────────── */
// # define STRIPE_P 100.0 /* μ周期：小→細縞／大→太縞       */
// # define SAT_BASE 0.3   /* 最小彩度                      */
// # define SAT_GAIN .35  /* 彩度の振れ幅                  */

// /* ── テクスチャ揺らぎ ──────────────────── */
// # define TEX_FREQ 42.0     /* μ周波数：大→細かいざらつき    */
// # define TEX_BR_GAIN 0.20  /* テクスチャが輝度へ与える影響  */
// # define TEX_SAT_GAIN 0.50 /* テクスチャが彩度へ与える影響  */

// /* ── RGB 合成の基準 ───────────────────── */
// # define HI 190.0 /* 明部の基準強度                */
// # define LO 0.0   /* 暗部の基準強度                */

// #endif /* COLOR_THEME_H */

// #ifndef COLOR_THEME_H
// # define COLOR_THEME_H

// /* ── Brightness ─────────────────── */
// # define BR_ADD 0.05
// # define BR_GAIN 1.30
// # define POW_EXP 0.25

// /* ── Stripe & Saturation ─────────── */
// # define STRIPE_P 7.0
// # define SAT_BASE 0.70
// # define SAT_GAIN 1.00

// /* ── Texture Ripple ──────────────── */
// # define TEX_FREQ 30.0
// # define TEX_BR_GAIN 0.10
// # define TEX_SAT_GAIN 0.60

// /* ── RGB Baseline ────────────────── */
// # define HI 190.0
// # define LO 0.0

// #endif /* COLOR_THEME_H */

// #ifndef COLOR_THEME_H
// # define COLOR_THEME_H

// /* Bright, punchy palette */
// # define BR_ADD 0.35
// # define BR_GAIN 0.90
// # define POW_EXP 0.35

// # define STRIPE_P 15.0
// # define SAT_BASE 0.80
// # define SAT_GAIN 0.90

// # define TEX_FREQ 60.0
// # define TEX_BR_GAIN 0.25
// # define TEX_SAT_GAIN 0.40

// # define HI 190.0
// # define LO 0.0

// #endif /* COLOR_THEME_H */

// #ifndef COLOR_THEME_H
// # define COLOR_THEME_H

// /* Soft pastel look */
// # define BR_ADD 0.22
// # define BR_GAIN 0.55
// # define POW_EXP 0.40

// # define STRIPE_P 25.0
// # define SAT_BASE 0.40
// # define SAT_GAIN 0.45

// # define TEX_FREQ 20.0
// # define TEX_BR_GAIN 0.15
// # define TEX_SAT_GAIN 0.30

// # define HI 190.0
// # define LO 0.0

// #endif /* COLOR_THEME_H */
/* ************************************************************************** */
/*                                                                            */
/*                     color_theme_flash.h（閃光テーマ）                     */
/*                                                                            */
/*      派手で鋭い色彩表現を目指した、フラクタル用カラーパラメータ群       */
/* ************************************************************************** */

#ifndef COLOR_THEME_H
# define COLOR_THEME_H

// ─── 輝度関連 ─────────────────────────────

// 最低輝度：発散しなかった領域（背景）に対する明るさ
// 値を上げる → 背景が明るくなる（灰色っぽく）
// 値を下げる → 背景が黒くなる
# define BR_ADD 0.05

// 輝度ゲイン：発散点の明るさの強調度
// 値を上げる → 縁が光線のように眩しくなる
// 値を下げる → 全体的に地味になる
# define BR_GAIN 1.80

// 輝度計算の指数：発散までの速さに応じた明暗のつけ方
// 値を上げる → 中心が急に明るくなる（コントラスト強）
// 値を下げる → 滑らかに明るさが広がる（グラデーション）
# define POW_EXP 0.20

// ─── ストライプ模様 ───────────────────────

// ストライプの周期：色の縞模様の細かさ
// 値を上げる → 縞が太くなる（周期長く）
// 値を下げる → 細かい縞が密に見える
# define STRIPE_P 12.0

// ─── 彩度（色の鮮やかさ） ───────────────────

// 最低彩度：発散しなかった点の色のくすみ具合
// 値を上げる → 背景も少し色味が出る
// 値を下げる → 背景が無彩色に近づく（白黒）
# define SAT_BASE 0.90

// 彩度の振れ幅：発散具合に応じた色の差の激しさ
// 値を上げる → 色がド派手になる
// 値を下げる → 色がなだらかで落ち着いた感じに
# define SAT_GAIN 1.30

// ─── テクスチャ（細かい模様表現） ──────────────

// テクスチャ周波数：明るさ・彩度の微細変化の周期
// 値を上げる → 超細かい模様（ノイズ感強）
// 値を下げる → ざっくりした模様（雲のよう）
# define TEX_FREQ 20.0

// テクスチャ明るさ変化量：明暗テクスチャの強さ
// 値を上げる → 模様の明暗が強調される（ざらざら）
// 値を下げる → なめらかで均一に近づく
# define TEX_BR_GAIN 0.35

// テクスチャ彩度変化量：色のゆらぎの強さ
// 値を上げる → 微妙に色味が揺れて幻想的になる
// 値を下げる → 色味が均一で落ち着いた印象に
# define TEX_SAT_GAIN 1.70

// ─── カラー範囲 ──────────────────────────

// RGB最大値（ホワイト）の定義（通常は255固定）
// 変更すると全体の色出力に影響
# define HI 255.0

// RGB最小値（ブラック）の定義（通常は0固定）
# define LO 0.0

#endif
