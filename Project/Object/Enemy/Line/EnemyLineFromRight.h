#pragma once
#include "EnemyLineBase.h"

/// <summary>
/// 右から出てくるライン系の敵
/// </summary>
class EnemyLineFromRight :	public EnemyLineBase
{
public:
	EnemyLineFromRight();
	~EnemyLineFromRight();

	virtual void Init(Vec2 pos, int width, int firstFrame, int secondFrame) override;
	virtual void Update()override;
	virtual void Draw()override;
};