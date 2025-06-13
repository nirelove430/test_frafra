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

/* color_theme_flash.h -------------------------------------------------- */
#ifndef COLOR_THEME_H
# define COLOR_THEME_H
# define BR_ADD 0.05  /* 真っ黒背景 */
# define BR_GAIN 1.60 /* 縁が光線並みに光る */
# define POW_EXP 0.20
# define STRIPE_P 3.5 /* 最細ストライプ */
# define SAT_BASE 0.90
# define SAT_GAIN 1.30  /* 彩度オーバー */
# define TEX_FREQ 120.0 /* 超細テクスチャ */
# define TEX_BR_GAIN 0.35
# define TEX_SAT_GAIN 0.70
# define HI 255.0 /* 最強ホワイト */
# define LO 0.0
#endif
