#pragma once
#include "Test.h"
#include <GL\glew.h>

	class TestClearColor :
		public Test
	{
	public:
		TestClearColor();
		virtual ~TestClearColor();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;

	private:
		float m_ClearColor[4];
	};
