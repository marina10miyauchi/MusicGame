#pragma once

#include<unordered_map>
#include<vector>
#include"Vector2.h"

class AnimatedSprite {
public:
	//�R���X�g���N�^
	AnimatedSprite() = default;
	//�f�X�g���N�^
	~AnimatedSprite();
	//�摜�t�@�C���ǂݍ���
	void Load(const std::string& fileName);
	//�摜�t�@�C���ǂݍ���
	void Load(const std::string& fileName, int row, int column);
	//�`��i�摜�S�́j
	void Draw(const Vector2& position)const;
	//�`��i�j
	void Draw(const Vector2& position, int x, int y, int w, int h)const;
	//�`��i�j
	void Draw(int no, const Vector2& position, const Vector2& center, const Vector2& scale, float rotation)const;
	//�`��i�j
	void Draw(int animation, int time, const Vector2& position, const Vector2& center, const Vector2& scale, float rotation)const;
	//�A�j���[�V�����ǉ�
	void AddAnimation(int animation, int start, int end, float time);
	//�L�[�t���[����ǉ�
	void AddKeyFrame(int animation, float time, int graph_no);
	//�L�[�t���[����ǉ�
	void AddKeyFrame(int animation, float time, int x, int y, int w, int h);
	//�A�j���[�V�����I�����Ԃ��擾
	float AnimationEndTime(int animation)const;
	//����
	void Clear();
	//�R�s�[�֎~
	AnimatedSprite(const AnimatedSprite& other) = delete;
	AnimatedSprite& operator=(const AnimatedSprite& other) = delete;
private:
	//�����摜
	using DivGraphs = std::vector<int>;
	//�L�[�t���[��
	using KeyFrame = std::pair<float, int >;
	//�L�[�t���[���z��
	using KeyFrames = std::vector<KeyFrame>;
	//�A�j���[�V�����z��
	using Animations = std::unordered_map<int, KeyFrames>;

private:
	//�L�[�t���[������
	const KeyFrame& FindKeyFrame(int animation, float time)const;

private:
	//���摜
	int graph_{ -1 };
	//�����摜
	DivGraphs div_graphs_;
	//�A�j���[�V�����f�[�^
	Animations animations_;

};