#pragma once
#include "EnemyLineBase.h"

/// <summary>
/// 上から出てくるライン系の敵
/// </summary>
class EnemyLineFromUpper	: public EnemyLineBase
{
public:
	EnemyLineFromUpper();
	~EnemyLineFromUpper();

	virtual void Init(Vec2 pos, int width, int firstFrame, int secondFrame) override;
	virtual void Update()override;
	virtual void Draw()override;
};

