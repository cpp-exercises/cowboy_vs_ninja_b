#include "doctest.h"

#include "sources/Character.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include <random>
#include <chrono>
#include <iostream>

using namespace ariel;
using namespace std;
//<--------------------Helper Functions-------------------->
//https://www.geeksforgeeks.org/generate-a-random-float-number-in-cpp/
double random_float(double min = -100, double max = 100) {
    std::default_random_engine generator(static_cast<unsigned long>(std::chrono::system_clock::now().time_since_epoch().count()));
    std::uniform_real_distribution<double> distribution(min, max);

    return distribution(generator);
}

auto create_yninja = [](double x = random_float(), double y = random_float()) {
    return new YoungNinja{"Bob", Point{x, y}};
};

auto create_tninja = [](double x = random_float(), double y = random_float()) {
    return new TrainedNinja{"Bob", Point{x, y}};
};

auto create_oninja = [](double x = random_float(), double y = random_float()) {
    return new OldNinja{"Bob", Point{x, y}};
};

auto create_cowboy = [](double x = random_float(), double y = random_float()) {
    return new Cowboy{"Bob", Point{x, y}};
};

auto random_char(double x = random_float(), double y = random_float()) -> Character * {
    int flag = static_cast<int>(random_float()) % 4;

    if (flag == 0) return create_cowboy(x, y);

    if (flag == 1) return create_yninja(x, y);

    if (flag == 2) return create_tninja(x, y);

    return create_oninja(x, y);
}

auto simulate_battle = [](Team &team, Team &team2) {
    int i = 0;
    while (team.stillAlive() && team2.stillAlive()) {
        if (i % 2 == 0) {
            team.attack(&team2);
        } else {
            team2.attack(&team);
        }
        i++;
    }
};
//<-------------------------------------------------->

const int MAX_TEAM = 10;


TEST_SUITE("Point class tests") {
    Point p1{1, 1};
    Point p2{2, 3};
    Point n1{-1, 1};
    Point n2{1, -9};
    Point n3{-1, -1};

    TEST_CASE("Distance method") {
        CHECK_EQ(p1.distance(p2), p2.distance(p1));
        CHECK_EQ(n1.distance(n2), n2.distance(n1));
        CHECK_EQ(n3.distance(p1), p1.distance(n3));

        CHECK_EQ(n2.distance(p1), 10);
        CHECK_EQ(p2.distance(n3), 5);
        CHECK_EQ(p1.distance(p1), 0);
    }

    TEST_CASE("moveTowards method") {
        double distance = p1.distance(p2);
        double half_p = distance / 2;
        double third_p = distance / 3;

        Point p3{Point::moveTowards(p1, p2, half_p)};
        CHECK_EQ(p3.distance(p2), doctest::Approx(half_p).epsilon(0.001));

        Point p4{Point::moveTowards(p1, p2, third_p)};
        CHECK_EQ(p4.distance(p2), doctest::Approx(third_p * 2).epsilon(0.001));

        // There is no such a thing as negative distance
        CHECK_THROWS_AS(Point::moveTowards(p1, p2, -1),std::invalid_argument);
    }

}

TEST_SUITE("Classes initialization tests and Team modification( add(),stillAlive() )") {

    TEST_CASE("Cowboy initialization") {
        Cowboy cowboy{"Bob", Point{2, 3}};
        CHECK(cowboy.hasboolets());
        CHECK_EQ(cowboy.getName(), "Bob");
        CHECK_EQ(cowboy.getLocation().distance(Point{2, 3}), 0);
        CHECK_NE(cowboy.getLocation().distance(Point{3, 2}), 0);

        CHECK(cowboy.isAlive());
    }

    TEST_CASE("YoungNinja initialization") {
        YoungNinja ninja{"Bob", Point{2, 3}};
        CHECK_EQ(ninja.getName(), "Bob");
        CHECK_EQ(ninja.getLocation().distance(Point{2, 3}), 0);
        CHECK_NE(ninja.getLocation().distance(Point{3, 2}), 0);

        CHECK(ninja.isAlive());
    }

    TEST_CASE("OldNinja initialization") {
        OldNinja old_ninja{"Bob", Point(2, 3)};
        CHECK_EQ(old_ninja.getName(), "Bob");
        CHECK_EQ(old_ninja.getLocation().distance(Point{2, 3}), 0);
        CHECK_NE(old_ninja.getLocation().distance(Point{3, 2}), 0);

        CHECK(old_ninja.isAlive());
    }

    TEST_CASE("TrainedNinja initialization") {
        TrainedNinja trained_ninja{"Bob", Point{2, 3}};
        CHECK_EQ(trained_ninja.getName(), "Bob");
        CHECK_EQ(trained_ninja.getLocation().distance(Point{2, 3}), 0);
        CHECK_NE(trained_ninja.getLocation().distance(Point{3, 2}), 0);

        CHECK(trained_ninja.isAlive());
    }

    TEST_CASE("Team initialization") {
        auto cowboy = create_cowboy(2, 3);
        auto ninja = create_yninja(2, 3);
        Team team{cowboy};
        CHECK_EQ(team.stillAlive(), 1);

        Team2 team2{ninja};
        CHECK_EQ(team2.stillAlive(), 1);
    }

    TEST_CASE("Team class add() and stillAlive() methods") {
        auto captain1 = create_oninja();
        auto captain2 = create_yninja();

        Team team1{captain1};
        Team2 team2{captain2};

        // Every addition should rise the value returned by stillAlive()
        for (int i = 0; i < MAX_TEAM - 1; i++) {
            auto cur1 = create_tninja();
            auto cur2 = create_cowboy();
            team1.add(cur1);
            team2.add(cur2);
            CHECK_EQ(team1.stillAlive(), i + 2);
            CHECK_EQ(team2.stillAlive(), i + 2);
        }

        // A team can have at most 10 teammates
        auto over = create_cowboy();
        CHECK_THROWS_AS(team1.add(over),std::runtime_error);
        CHECK_THROWS_AS(team2.add(over),std::runtime_error);
        delete over;
    }

    TEST_CASE("Appointing the same captain to different teams") {
        auto captain = create_cowboy();
        auto captain2 = create_yninja();

        Team team1{captain};
        CHECK_THROWS_AS(Team{captain},std::runtime_error);
        CHECK_THROWS_AS(Team2{captain},std::runtime_error);

        Team team2{captain2};
        CHECK_THROWS_AS(Team{captain2},std::runtime_error);
        CHECK_THROWS_AS(Team2{captain2},std::runtime_error);
    }

    TEST_CASE("Adding the same character to different teams") {
        auto captain1 = create_tninja();
        auto captain2 = create_oninja();
        auto captain3 = create_yninja();

        Team team1{captain1};
        Team team2{captain2};
        Team2 team3{captain3};

        auto teammate1 = create_cowboy();
        auto teammate2 = create_oninja();

        team1.add(teammate1);
        team1.add(teammate2);

        CHECK_THROWS_AS(team2.add(teammate1),std::runtime_error);
        CHECK_THROWS_AS(team3.add(teammate1),std::runtime_error);
        CHECK_THROWS_AS(team2.add(teammate2),std::runtime_error);
        CHECK_THROWS_AS(team3.add(teammate2),std::runtime_error);
    }
}


TEST_SUITE("Battle related methods") {

    TEST_CASE("Cowboy shoot() and reload() methods") {
        auto cowboy = create_cowboy();
        auto target = create_oninja();

        auto shoot = [&](int times) {
            for (int i = 0; i < times; i++) {
                cowboy->shoot(target);
            }
        };

        shoot(6);
        CHECK_FALSE(cowboy->hasboolets());
        CHECK_NOTHROW(cowboy->shoot(target)); // This should not damage the target
        cowboy->reload();

        shoot(2);
        cowboy->reload();
        shoot(6);
        CHECK(target->isAlive()); // Target should still be alive with 10 hit points if the cowboys damage is 10
        shoot(1);
        CHECK(target->isAlive()); // Reloading when the magazine isn't empty shouldn't result in more than 6 bullets, the previous shoot should have no effect
        cowboy->reload();
        shoot(1);
        CHECK_FALSE(target->isAlive()); // Target should be dead
        delete cowboy;
        delete target;
    }


    TEST_CASE("Ninjas hit points are different") {
        auto old = create_oninja();
        auto trained = create_tninja();
        auto young = create_yninja();
        auto cowboy = create_cowboy();
        for (int i = 0; i < 15; i++) {
            cowboy->reload();

            // After 10 shots, young should die
            if (i < 10) {
                CHECK(young->isAlive());
                cowboy->shoot(young);
            }

            // After 12 shots, trained should die
            if (i < 12) {
                CHECK(trained->isAlive());
                cowboy->shoot(trained);
            }

            // Old should only die on the last iteration of the for loop
            CHECK(old->isAlive());
            cowboy->shoot(old);
        }

        CHECK_FALSE((old->isAlive() || young->isAlive() || trained->isAlive()));

        delete old ;
        delete trained ;
        delete young ;
        delete cowboy ;
    }

    TEST_CASE("Ninjas speeds are different") {
        OldNinja old{"Bob", Point{random_float(0) + 15, random_float(0) + 15}};
        TrainedNinja trained{"Kung fu panda", Point{random_float(0) + 15, random_float(0) + 15}};
        YoungNinja young{"Karate kid", Point{random_float(0) + 15, random_float(0) + 15}};
        Cowboy cowboy{"Clint", Point{0, 0}}; 

        double old_distance = old.distance(&cowboy);
        double young_distance = young.distance(&cowboy);
        double trained_distance = trained.distance(&cowboy);

        old.move(&cowboy);
        trained.move(&cowboy);
        young.move(&cowboy);

        // The new distance should equal the old distance minus the speed of the specific ninja
        CHECK_EQ(old.distance(&cowboy),
                 doctest::Approx(old_distance - 8).epsilon(0.001));
        CHECK_EQ(trained.distance(&cowboy),
                 doctest::Approx(trained_distance - 12).epsilon(0.001));
        CHECK_EQ(young.distance(&cowboy),
                 doctest::Approx(young_distance - 14).epsilon(0.001));
    }

    TEST_CASE("Ninjas can only slash when distance is less than 1") {
        OldNinja old{"Bob", Point{0, 0}};
        TrainedNinja trained{"Kung fu panda", Point{0, 0}};
        YoungNinja young{"Karate kid", Point{0.5, 0.5}};
        Cowboy cowboy{"Clint", Point{0.5, 0.5}};

        for (int i = 0; i < 1; i++) {
            old.slash(&cowboy);
            young.slash(&cowboy);
        }

        CHECK(cowboy.isAlive());

        old.slash(&cowboy);
        CHECK_FALSE(cowboy.isAlive());

        YoungNinja ninja{"Bob", Point{-0.5, 0.5}}; // Distance from young is exactly one
        OldNinja ninja2{"Bob", Point{2, 2}};

        // These attacks should have no affect
        for (int i = 0; i < 20; i++) {
            trained.slash(&ninja2);
            old.slash(&ninja2);
            young.slash(&ninja2);
        }

        for(int i = 0 ; i < 1 ; i++){
            old.slash(&ninja);
            young.slash(&ninja);
        }
        CHECK(ninja.isAlive());
        CHECK(ninja2.isAlive());
    }


    TEST_CASE("Dead characters cannot attack and characters cannot attack a dead enemy") {
        OldNinja old{"Bob", Point{0, 0}};
        YoungNinja young{"Bob", Point{0, 0}};
        Cowboy cowboy{"Bob", Point{0, 0}};
        TrainedNinja trained("Bob", Point{0, 0});
        OldNinja old2{"Bob", Point{0, 0}};
        YoungNinja young2{"Bob", Point{0, 0}};
        Cowboy cowboy2{"Bob", Point{0, 0}};
        TrainedNinja trained2("Bob", Point{0, 0});

        while (old2.isAlive()) {
            young.slash(&old2);
        }

        while (young2.isAlive()) {
            young.slash(&young2);
        }

        while (trained2.isAlive()) {
            young.slash(&trained2);
        }

        while (cowboy2.isAlive()) {
            young.slash(&cowboy2);
        }


        // Attacking a dead character
        CHECK_THROWS_AS(young.slash(&old2), std::runtime_error);
        CHECK_THROWS_AS(cowboy.shoot(&old2), std::runtime_error);
        CHECK_THROWS_AS(trained.slash(&cowboy2), std::runtime_error);
        CHECK_THROWS_AS(old.slash(&cowboy2), std::runtime_error);

        // Calling the attacking method of a dead character
        CHECK_THROWS_AS(young2.slash(&old), std::runtime_error);
        CHECK_THROWS_AS(cowboy2.shoot(&old), std::runtime_error);
        CHECK_THROWS_AS(trained2.slash(&cowboy), std::runtime_error);
        CHECK_THROWS_AS(old2.slash(&cowboy), std::runtime_error);
    }

    TEST_CASE("Sending nullptr to the attack() method") {
        auto cowboy = create_cowboy();
        auto ninja = create_tninja();
        Team team{cowboy};
        Team2 team2{ninja};

        CHECK_THROWS_AS(team.attack(nullptr), std::invalid_argument);
        CHECK_THROWS_AS(team2.attack(nullptr), std::invalid_argument);
    }

    TEST_CASE("Sending negative value to hit()") {
        auto cowboy = create_cowboy();
        auto yninja = create_yninja();
        auto oninja = create_oninja();
        auto tninja = create_tninja();

        CHECK_THROWS_AS(cowboy->hit(-random_float(1, 100)), std::invalid_argument);
        CHECK_THROWS_AS(yninja->hit(-random_float(1, 100)), std::invalid_argument);
        CHECK_THROWS_AS(oninja->hit(-random_float(1, 100)), std::invalid_argument);
        CHECK_THROWS_AS(tninja->hit(-random_float(1, 100)), std::invalid_argument);

        delete cowboy;
        delete yninja;
        delete oninja;
        delete tninja;
    }

    TEST_CASE("Dead cowboy can not reload") {
        auto cowboy = create_cowboy();
        auto cowboy2 = create_cowboy();

        cowboy->shoot(cowboy2);
        while (cowboy2->isAlive()) {
            cowboy->shoot(cowboy2);
            cowboy->reload();
        }

        CHECK_THROWS_AS(cowboy2->reload(), std::runtime_error);
        delete cowboy;
        delete cowboy2;
    }

    TEST_CASE("No self harm") {
        auto cowboy = create_cowboy();
        auto yninja = create_yninja();
        auto oninja = create_oninja();
        auto tninja = create_tninja();

        CHECK_THROWS_AS(cowboy->shoot(cowboy), std::runtime_error);
        CHECK_THROWS_AS(yninja->slash(yninja), std::runtime_error);
        CHECK_THROWS_AS(oninja->slash(oninja), std::runtime_error);
        CHECK_THROWS_AS(tninja->slash(tninja), std::runtime_error);

        delete cowboy;
        delete yninja;
        delete oninja;
        delete tninja;
    }
}

TEST_SUITE("Battle simulations") {

    auto multi_attack = [](int n, Team &attacker, Team &defender) {
        for (int i = 0; i < n; i++) {
            if (defender.stillAlive()) {
                attacker.attack(&defender);
            }
        }
    };

    TEST_CASE("Characters attack the closest enemy to the captain and ignore dead enemies ") {
        Team team{create_cowboy(-1, -1)};
        team.add(create_yninja(0, 0));
        team.add(create_oninja(-0.5, -0.5));
        team.add(create_tninja(0.5, 0.5));
        team.add(create_cowboy());

        CHECK_EQ(team.stillAlive(), 5);

        auto young_ninja = create_yninja(0, 0);
        auto trained_ninja = create_tninja(1, 1);
        auto old_ninja = create_oninja(2, 2);
        auto young_ninja2 = create_yninja(3, 3);
        auto cowboy = create_cowboy(-6, -6);
	auto cowboy2 = create_cowboy(-7, -7);
	auto cowboy3 = create_cowboy(-8, -8);
        Team team2{young_ninja};
        team2.add(trained_ninja);
        team2.add(old_ninja);
        team2.add(young_ninja2);
        team2.add(cowboy);
	team2.add(cowboy2);
	team2.add(cowboy3);

        CHECK_EQ(team2.stillAlive(), 7);

        multi_attack(2, team, team2);
        CHECK_FALSE(young_ninja->isAlive()); // Young ninja should be dead
        CHECK((trained_ninja->isAlive() && old_ninja->isAlive() &&
               young_ninja2->isAlive())); // Everyone else should still be alive

        team.attack(&team2);
        CHECK((!trained_ninja->isAlive() && old_ninja->isAlive() &&
               young_ninja2->isAlive())); // No one should die in the attack

        multi_attack(2, team, team2);
        CHECK_FALSE(trained_ninja->isAlive()); // Trained ninja should be dead
        CHECK((!old_ninja->isAlive() && young_ninja2->isAlive()));

        multi_attack(4, team, team2);
        CHECK_FALSE(old_ninja->isAlive()); // Old ninja should be dead
        CHECK(!young_ninja2->isAlive());

        multi_attack(2, team, team2);
        CHECK_NOTHROW(team.attack(
                &team2)); // The entire enemy team will be dead before every cowboy shoots, the attack should stop and not throw an exception
        CHECK_FALSE(young_ninja2->isAlive()); // Young ninja should be dead
        CHECK_THROWS_AS(team.attack(&team2), std::runtime_error); // Attacking a dead team should throw an exception
    }

    /*
     * In this test only cowboys are used because they are stationary. This allows us to better keep track of everyone's position to better test for captains assignment.
     * The characters are organized as such:
     * 2-1--2-[C1]-[C2]--2--1
     * A hyphen (-) denotes a distance of one.
     * */
    TEST_CASE("The closest teammate to the captain is appointed as captain") {

        auto team_c1 = create_cowboy(0, 0);
        auto team2_c1 = create_cowboy(-2, 0);
        auto team_c2 = create_cowboy(-3, 0);
        auto team2_c2 = create_cowboy(1, 0);//
        auto team2_c3 = create_cowboy(3, 0);//
        auto team_c3 = create_cowboy(5, 0);//
        auto team2_c4 = create_cowboy(-5, 0);

        Team team1{team_c1};
        team1.add(team_c2);
        team1.add(team_c3);
        Team2 team2{team2_c2};
        team2.add(team2_c1);
        team2.add(team2_c3);
        team2.add(team2_c4);

        multi_attack(4, team1, team2);

        // The captain of team2 is the closest enemy to the captain of team1, and therefore should be dead.
        CHECK((!team2_c2->isAlive() && team2_c1->isAlive() && team2_c3->isAlive() && team2_c4->isAlive()));

        // At this point, the captain should be team2_c3; hence, the next enemy to be attacked by team2 should team_c3.
        multi_attack(6, team2, team1);
        CHECK((!team_c3->isAlive() && team_c1->isAlive() && team_c2->isAlive()));


        // Killing the new captain
        while (team2_c3->isAlive()) {
            team_c1->reload();
            team_c1->shoot(team2_c3);
        }

        CHECK((!team2_c2->isAlive() && team2_c1->isAlive() && !team2_c3->isAlive() && team2_c4->isAlive()));

        //Next captain should be team2_c1, hence, the next enemy to be attacked by team2 should team_cc.
        multi_attack(7, team2, team1);
        CHECK((!team_c3->isAlive() && team_c1->isAlive() && !team_c2->isAlive()));

        while (team1.stillAlive() && team2.stillAlive()) {
            team1.attack(&team2);
            team2.attack(&team1);
        }
    }


    // In this test the attacking team is again composed of cowboys, this is because cowboys are stationary, and we can better predict the damage done in every attack.
    TEST_CASE("If several enemies are equidistant from the captain, only a single enemy should still be targeted.") {
        auto cowboy = create_cowboy();
        Team team{cowboy};
        for (int i = 0; i < 4; i++) {
            team.add(create_cowboy());
        }

        auto char1 = create_yninja(0, 0);
        auto char2 = create_yninja(0, 0);
        auto char3 = create_yninja(0, 0);
        auto char4 = create_yninja(0, 0);

        Team team2{char1};
        team2.add(char2);
        team2.add(char3);
        team2.add(char4);

        // Young ninjas have 100 hit points. 2 attacks should result in 10 shots, killing only one, if they all target the same enemy
        multi_attack(2, team, team2);
        CHECK_EQ(team2.stillAlive(), 3);

        // Two more attacks should result in another single casualty
        multi_attack(2, team, team2);
        CHECK_EQ(team2.stillAlive(), 2);

        // Two more attacks should result in another single casualty
        multi_attack(2, team, team2);
        CHECK_EQ(team2.stillAlive(), 1);

        //The cowboys should need to reload, hence three attacks are needed
        multi_attack(3, team, team2);
        CHECK_EQ(team2.stillAlive(), 0);

    }

    // Similar to the previous test, only this time the captain is mobile.
    TEST_CASE("When the captain moves, a different enemy should be targeted") {
        auto t11 = create_yninja(random_float(1.5, 1.6), random_float(1.5, 1.6));
        auto t12 = create_oninja(random_float(2.5, 2.6), random_float(2.7, 2.5));
        auto t13 = create_tninja(random_float(3.5, 3.6), random_float(3.5, 3.6));
        auto t14 = create_cowboy();
        Team team{t11};
        team.add(t12);
        team.add(t13);
        team.add(t14);

        auto t21 = create_cowboy(random_float(-1.5, -1.5), random_float(-1.5, -1.6));
        auto t22 = create_tninja(random_float(-2.5, -2.6), random_float(-2.5, -2.6));
        auto t23 = create_yninja(random_float(-3.5, -3.6), random_float(-3.5, -3.6));
        Team team2{t21};
        team2.add(t22);
        team2.add(t23);

        team.attack(&team2);
        CHECK_EQ(t11->distance(t21), doctest::Approx(0).epsilon(0.001));
        CHECK_EQ(t12->distance(t21), doctest::Approx(0).epsilon(0.001));
        CHECK_EQ(t13->distance(t21), doctest::Approx(0).epsilon(0.001));
        CHECK(t21->isAlive());
        multi_attack(3, team, team2);
        CHECK_FALSE(t21->isAlive()); // The first move in the attack should be a shot by the cowboy that kills t21

        // After the cowboy kills t21, all the ninja should move towards t22.
        CHECK_EQ(t11->distance(t22), doctest::Approx(0).epsilon(0.001));
        CHECK_EQ(t12->distance(t22), doctest::Approx(0).epsilon(0.001));
        CHECK_EQ(t13->distance(t22), doctest::Approx(0).epsilon(0.001));

        // Moving the captain behind t23, making t23 the new closest enemy.
        Cowboy decoy{"decoy", Point{-5, -5}};
        decoy.shoot(t23); //A shot needed to kill t23 in the next attack without making the ninjas move to next target
        t11->move(&decoy);
        multi_attack(3, team, team2);
        CHECK_EQ(t11->distance(t23), doctest::Approx(0).epsilon(0.001));
        CHECK_EQ(t12->distance(t23), doctest::Approx(0).epsilon(0.001));
        CHECK_EQ(t13->distance(t23), doctest::Approx(0).epsilon(0.001));

        CHECK((!t21->isAlive() && !t22->isAlive() && !t23->isAlive()));

        CHECK_NOTHROW(simulate_battle(team, team2));
    }

    TEST_CASE("Run full battles using random_char to ensure full functionality") {
        SUBCASE("Team vs Team") {
            Team team{random_char()};
            Team team2{random_char()};
            for (int i = 0; i < MAX_TEAM - 1; i++) {
                team.add(random_char());
                team2.add(random_char());
            }

            simulate_battle(team, team2);

            CHECK(((team.stillAlive() && !team2.stillAlive()) || (!team.stillAlive() && team2.stillAlive())));
        }

        SUBCASE("Team vs Team2") {
            Team team{random_char()};
            Team2 team2{random_char()};
            for (int i = 0; i < MAX_TEAM - 1; i++) {
                team.add(random_char());
                team2.add(random_char());
            }

            simulate_battle(team, team2);

            CHECK(((team.stillAlive() && !team2.stillAlive()) || (!team.stillAlive() && team2.stillAlive())));
        }

        SUBCASE("Team2 vs Team2") {
            Team2 team{random_char()};
            Team2 team2{random_char()};
            for (int i = 0; i < MAX_TEAM - 1; i++) {
                team.add(random_char());
                team2.add(random_char());
            }

            simulate_battle(team, team2);

            CHECK(((team.stillAlive() && !team2.stillAlive()) || (!team.stillAlive() && team2.stillAlive())));
        }
    }
}