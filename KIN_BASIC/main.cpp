#include <iostream>
#include <kdl/chain.hpp>
#include <kdl/segment.hpp>
#include <kdl/joint.hpp>
#include <kdl/frames.hpp>
#include <kdl/chainfksolverpos_recursive.hpp>
#include <kdl/jntarray.hpp>
#include <vector>
#include <fstream>
#include <cmath>

int main() {
    // Create a kinematic chain
    KDL::Chain chain;

    // Add two segments with rotational joints
    chain.addSegment(KDL::Segment("Link1", KDL::Joint(KDL::Joint::RotZ), KDL::Frame(KDL::Vector(1, 0, 0))));
    chain.addSegment(KDL::Segment("Link2", KDL::Joint(KDL::Joint::RotZ), KDL::Frame(KDL::Vector(1, 0, 0))));

    // Set up the forward kinematics solver
    KDL::ChainFkSolverPos_recursive fk_solver(chain);

    // Define joint positions (initial positions)
    KDL::JntArray joint_positions(2);
    joint_positions(0) = 0.0;  // Initial joint angle for the first joint
    joint_positions(1) = 0.0;  // Initial joint angle for the second joint

    // Open a file to save the data for plotting
    std::ofstream output_file("trajectory_data.txt");

    // Define a trajectory for joint movements (for example, simple linear motion)
    int num_steps = 100;  // Number of steps in the trajectory
    for (int i = 0; i < num_steps; ++i) {
        joint_positions(0) = i * 0.1;  // Change joint 1 linearly from 0 to 5
        joint_positions(1) = i * 0.1;  // Change joint 2 linearly from 0 to 5

        // Compute the end effector pose
        KDL::Frame end_effector_pose;
        fk_solver.JntToCart(joint_positions, end_effector_pose);

        // Write the end effector position to the file
        output_file << end_effector_pose.p.x() << " " 
                    << end_effector_pose.p.y() << " " 
                    << end_effector_pose.p.z() << std::endl;
    }

    output_file.close();

    std::cout << "Trajectory data saved to 'trajectory_data.txt'. Run the Python script to visualize." << std::endl;
    return 0;
}

