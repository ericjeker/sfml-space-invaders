// Copyright (c) Eric Jeker. All Rights Reserved.

#ifndef ANIMATORCOMPONENT_H
#define ANIMATORCOMPONENT_H

#include "Tween.h"

#include <functional>

#include "SFML/System/Time.hpp"

/**
 * AnimeComponent is a lightweight interpolation engine driving a single float value
 * from start to end in duration milliseconds and at every frame calls the setter
 * method.
 */
class AnimatorComponent
{
public:
	using Setter = std::function<void(float)>;

	struct Tracker
	{
		Setter setter;
		float from = 0.f;
		float to = 0.f;
		float duration = 0.f;
		bool loop = false;
		float accumulator = 0.f;
		bool isGrowing = true;

		bool Update(const float dt)
		{
			accumulator = std::min(accumulator + dt, duration);
			const float alpha = duration == 0.f ? 1.f : accumulator / duration;
			float value = 0.f;

			// Call the setter function
			// TODO: Make the Tweening function a parameter
			if (isGrowing)
			{
				value = from + (to - from) * easeInOutSine(alpha);
			}
			else
			{
				value = from + (to - from) * (1.f - easeInOutSine(alpha));
			}

			setter(value);

			if (loop)
			{
				if (alpha >= 1.f)
				{
					accumulator = 0.f;
					isGrowing = !isGrowing;
				}

				return false;
			}

			return accumulator >= duration;
		}
	};

	// TODO: at some point this is going to be too many parameters...
	template <typename SetterT>
	void AddTracker(SetterT&& setter, const float from, const float to, const float duration, const bool loop)
	{
		_trackers.emplace_back(Tracker{std::forward<SetterT>(setter), from, to, duration, loop});
	}

	void Update(const sf::Time& deltaTime)
	{
		if (_paused)
		{
			return;
		}

		const float seconds = deltaTime.asSeconds();
		for (auto it = _trackers.begin(); it != _trackers.end();)
		{
			it = it->Update(seconds) ? _trackers.erase(it) : ++it;
		}
	};

	void Clear()
	{
		_trackers.clear();
	}

	[[nodiscard]] bool IsEmpty() const
	{
		return _trackers.empty();
	}

	void Reset()
	{
		for (auto& tracker : _trackers)
		{
			tracker.accumulator = 0.f;
		}
	}

	void Pause()
	{
		_paused = true;
	}

	void Resume()
	{
		_paused = false;
	}

private:
	std::vector<Tracker> _trackers;
	bool _paused = false;
};

#endif // ANIMATORCOMPONENT_H
