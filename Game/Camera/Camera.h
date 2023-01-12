#pragma once

#include "Game/Vector2D/Vector2D.h"
#include "Game/Matrix3x3/Matrix3x3.h"

class Camera {
public:
	Camera();
	~Camera();

public:
	/// <summary>
	/// �J�����̍X�V����
	/// <para>�f�o�b�O�p</para>
	/// </summary>
	void Update();

	/// <summary>
	/// �J�����̍X�V����
	/// </summary>
	/// <param name="worldPos">�J�����̃��[���h���W</param>
	/// <param name="cameraPos">�J�����̃X�N���[�����W</param>
	/// <param name="scale">�\������傫��</param>
	/// <param name="shake">�V�F�C�N���邩�ǂ���</param>
	void Update(const Vector2D& worldPos, const Vector2D& cameraPos, const float& scale = 1.0f, const bool& shake = false);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="worldPos">�J�����̃��[���h���W</param>
	/// <param name="cameraPos">�J�����̃X�N���[�����W</param>
	/// <param name="drawLeftTop">�J�������̈ڂ��͈�(����)</param>
	/// <param name="drawRightBottom">�J�������̈ڂ��͈�(�E��)</param>
	/// <param name="shake">�V�F�C�N���肩�Ȃ���</param>
	void Update(const Vector2D& worldPos, const Vector2D& cameraPos, const Vector2D& drawLeftTop, const Vector2D& drawRightBottom, const bool& shake = false);

	/// <summary>
	/// DrawQuad
	/// </summary>
	/// <param name="quad"></param>
	/// <param name="texture"></param>
	/// <param name="animationSpd">������傫������قǒx���Ȃ�</param>
	/// <param name="animationStop">true�Ȃ�A�j���[�V���������Ȃ�</param>
	/// <param name="color">���Ɏw�肵�Ȃ��ꍇWHITE�ɂȂ�</param>
	void DrawQuad(class Quad quad, class Texture& texture, const int& animationSpd, const bool& animationStop, const unsigned int& color = 0xffffffff) const;

	/// <summary>
	/// DrawQuad
	/// </summary>
	/// <param name="quad"></param>
	/// <param name="texture"></param>
	/// <param name="deg">�p�x(�x���@)�B�\����̂݉�]������</param>
	/// <param name="animationSpd">������傫������قǒx���Ȃ�</param>
	/// <param name="animationStop">true�Ȃ�A�j���[�V���������Ȃ�</param>
	/// <param name="color">���Ɏw�肵�Ȃ��ꍇWHITE�ɂȂ�</param>
	void DrawQuad(class Quad quad, class Texture& texture, float deg, const int& animationSpd, const bool& animationStop, const unsigned int& color = 0xffffffff) const;

	/// <summary>
	/// DrawUI
	/// <para>�J�������ǂ��ɂ��悤���\������</para>
	/// </summary>
	/// <param name="quad"></param>
	/// <param name="texture"></param>
	/// <param name="animationSpd">������傫������قǒx���Ȃ�</param>
	/// <param name="animationStop">true�Ȃ�A�j���[�V���������Ȃ�</param>
	void DrawUI(class Quad quad, class Texture& texture, const int& animationSpd, const bool& animationStop, const unsigned int& color = 0xffffffff) const;

	/// <summary>
	/// �J�������ɉf���Ă邩�ǂ���
	/// </summary>
	/// <param name="pos">�|�W�V����</param>
	/// <param name="drawLength">�`�拗��(�f�t�H���g��0.0f)</param>
	/// <returns>
	/// <para>ture:�f���Ă�</para>
	/// <para>false:�f���ĂȂ�</para>
	/// </returns>
	bool isDraw(Vector2D pos, const float& drawLength = 0.0f) const;

	Vector2D getPos() const;
	Vector2D getDrawLeftTop() const;
	Vector2D getDrawRightBottom() const;
	Vector2D getDrawSize() const;

private:
	void Shake();

private:
	// �J�������W(�^��)
	Vector2D worldPos;

	Vector2D screenPos;

	Vector2D drawLeftTop;

	Vector2D drawRightBottom;

	// �ǂ̂��炢�̑傫���ŕ\�����邩(�f�t�H���g��1.0f)
	float scale;

	// �J�����̉f��T�C�Y
	Vector2D size;

	// �V�F�C�N�̑傫��
	Vector2D shakeScale;

	// �r���[�s��
	Matrix3x3 viewMatrix;

	// ���ˉe�s��
	Matrix3x3 NorDevMatrix;

	// �r���[�|�[�g�s��
	Matrix3x3 viewPortMatrix;

	// �����_�����O�s��
	Matrix3x3 vpvpMatrix;

public:
	// �t���[��
	class Frame* frame;
};