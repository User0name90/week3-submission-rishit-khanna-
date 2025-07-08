# week3-submission-rishit-khanna-
Question 1:
  q1_publisher_lambda_function.cpp
  q1_suscriber_lambda_function.cpp
  Use commands:
    ros2 run kratos_rishitkhanna talker
    ros2 run kratos_rishitkhanna listener

Question 2:
  q2_first_publisher.cpp (publishes on /s1 topic)
  q2_second_publisher.cpp (publishes on /s2 topic and subscribe to /s1)
  Use commands:
    ros2 run kratos_rishitkhanna S_one
    ros2 run kratos_rishitkhanna S_two

Question 3:
  file in msg/Roverquestionthree.msg
  Use commands:
    ros2 interface show tutorial_interfaces/msg/Roverquestionthree

Question 4:
  q4_seconds.cpp
  q4_minutes.cpp
  q4_hours.cpp
  q4_clock.cpp
  Use commands:
    ros2 run kratos_rishitkhanna second (publish on /second topic)
    ros2 run kratos_rishitkhanna minute (publish on /minute topic and suscribe to /second)
    ros2 run kratos_rishitkhanna hour (publish on /hour topic and suscribe to /minute)
    ros2 run kratos_rishitkhanna clock (publish on /clock suscribe to /hour /minute /second)














    
