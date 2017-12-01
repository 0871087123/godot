/*************************************************************************/
/*  generic_6dof_joint_bullet.h                                          */
/*  Author: AndreaCatania                                                */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                    http://www.godotengine.org                         */
/*************************************************************************/
/* Copyright (c) 2007-2017 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2017 Godot Engine contributors (cf. AUTHORS.md)    */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef GENERIC_6DOF_JOINT_BULLET_H
#define GENERIC_6DOF_JOINT_BULLET_H

#include "joint_bullet.h"

class RigidBodyBullet;

class Generic6DOFJointBullet : public JointBullet {
	class btGeneric6DofConstraint *sixDOFConstraint;

public:
	Generic6DOFJointBullet(RigidBodyBullet *rbA, RigidBodyBullet *rbB, const Transform &frameInA, const Transform &frameInB, bool useLinearReferenceFrameA);

	virtual PhysicsServer::JointType get_type() const { return PhysicsServer::JOINT_6DOF; }

	Transform getFrameOffsetA() const;
	Transform getFrameOffsetB() const;
	Transform getFrameOffsetA();
	Transform getFrameOffsetB();

	void set_linear_lower_limit(const Vector3 &linearLower);
	void set_linear_upper_limit(const Vector3 &linearUpper);

	void set_angular_lower_limit(const Vector3 &angularLower);
	void set_angular_upper_limit(const Vector3 &angularUpper);

	void set_param(Vector3::Axis p_axis, PhysicsServer::G6DOFJointAxisParam p_param, real_t p_value);
	real_t get_param(Vector3::Axis p_axis, PhysicsServer::G6DOFJointAxisParam p_param) const;

	void set_flag(Vector3::Axis p_axis, PhysicsServer::G6DOFJointAxisFlag p_flag, bool p_value);
	bool get_flag(Vector3::Axis p_axis, PhysicsServer::G6DOFJointAxisFlag p_flag) const;
};

#endif
