// Copyright (c) Eric Jeker. All Rights Reserved.

#ifndef TWEEN_H
#define TWEEN_H
#include <cmath>

constexpr auto PI_FLOAT = static_cast<float>(M_PI);

/**
 * Computes the ease-in-out sine interpolation for a given normalized time.
 * The function accelerates during the first half and decelerates during the second half.
 *
 * @param t A float representing the normalized time in the range [0, 1].
 * @return A float representing the interpolated value corresponding to the input-normalized time.
 */
inline float easeInOutSine(const float t)
{
	return 0.5f * (1.0f - std::cos(PI_FLOAT * t));
}

#endif // TWEEN_H
