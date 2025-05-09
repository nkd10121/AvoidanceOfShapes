#include "EnemyLineFromLeft.h"
#include "DxLib.h"
#include "Game.h"

EnemyLineFromLeft::EnemyLineFromLeft()
{
}

EnemyLineFromLeft::~EnemyLineFromLeft()
{
}

void EnemyLineFromLeft::Init(Vec2 pos, int width, int firstFrame, int secondFrame)
{
	m_isExist = true;

	//初期x座標の設定
	m_startPos.x = 0;
	m_endPos.x = 0;

	//初期y座標の設定
	m_startPos.y = pos.y;
	m_endPos.y = m_startPos.y + width;

	m_waitFrame = firstFrame;
	m_disappearFrame = secondFrame;

}

void EnemyLineFromLeft::Update()
{
	//もし存在しなかったらUpdateを実行しない
	if (!m_isExist)
		return;

	m_frame++;

	m_color = 0xff00ff;

	//secondTime以降(戻っていく)
	if (m_frame >= m_disappearFrame)
	{
		m_endPos.x -= 320;
	}
	//firstTime~secondTimeの間(本動作)
	else if (m_frame >= m_waitFrame)
	{
		m_endPos.x += 320;
		m_color = 0xffffff;
	}
	//0~firstTimeの間(予備動作的な)
	else if (m_frame >= 0)
	{
		m_endPos.x += 0.4f;
	}

	//敵座標の補正
	if (m_endPos.x >= Game::kScreenWidth)
	{
		m_endPos.x = Game::kScreenWidth;
		if (!m_isShake)
		{
			m_shakeFrame = 12;
			m_isShake = true;
		}
		m_color = 0xff00ff;
	}

	//敵座標の補正&isExistフラグの処理
	if (m_endPos.x <= 0)
	{
		m_isExist = false;
		m_endPos.x = 0;
	}

	if (m_shakeFrame != 0)
	{
		m_shakeFrame--;
	}

	//当たり判定の設定

	m_col.SetBox(m_startPos.x, m_startPos.y,
		m_endPos.x, m_endPos.y);
}

void EnemyLineFromLeft::Draw()
{
	//もし存在しなかったらUpdateを実行しない
	if (!m_isExist)
		return;

	//予測線的なのの描画
	if (m_frame <= m_disappearFrame)
	{
		DrawBox(static_cast<int>(m_startPos.x), static_cast<int>(m_startPos.y),
			Game::kScreenWidth, static_cast<int>(m_endPos.y),
			0x440044, true);
	}

	DrawBox(static_cast<int>(m_startPos.x), static_cast<int>(m_startPos.y),
		static_cast<int>(m_endPos.x), static_cast<int>(m_endPos.y),
		0xff00ff, true);

#ifdef _DEBUG
	//DrawFormatString(0, 720 - 16, 0xffffff, "endPos.y : %d", endPos.y);
	m_col.DrawColBox(0xffffff);
#endif
}