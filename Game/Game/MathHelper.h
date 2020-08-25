#ifndef MATH_HELPER_H_
#define MATH_HELPER_H_

// �}�X�w���p�[�N���X
class MathHelper {
public:
	// �΂̒l��\���܂��B
	static const float Pi;
	// �l���w�肳�ꂽ�͈͓��ɐ������܂�
	static float Clamp(float value, float min, float max);
	// 2�̒l�̍��̐�Βl���v�Z���܂�
	static float Distance(float n1, float n2);
	// 2�̒l�̊Ԃ���`��Ԃ��܂�
	static float Lerp(float value1, float value2, float amount);
	// ���W�A����x�ɕϊ����܂��B
	static float ToDegrees(float radians);
	// �x�����W�A���ɕϊ����܂��B
	static float ToRadians(float degree);
	// �T�C��
	static float Sin(float degree);
	// �R�T�C��
	static float Cos(float degree);
	// �^���W�F���g
	static float Tan(float degree);
	// �t�T�C��
	static float ASin(float s);
	// �t�R�T�C��
	static float ACos(float c);
	// �t�^���W�F���g
	static float ATan(float y, float x);
};

#endif
