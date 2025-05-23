#pragma once
#include "EnemyLineBase.h"

/// <summary>
/// 下から出てくるライン系の敵
/// </summary>
class EnemyLineDown : public EnemyLineBase
{
public:
	EnemyLineDown();
	~EnemyLineDown();

	virtual void Init(Vec2 pos, int width, int firstFrame, int secondFrame) override;
	virtual void Update()override;
	virtual void Draw()override;

};