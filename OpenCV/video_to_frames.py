def video_to_frames(input_loc, output_loc):
    """Function to extract frames from input video file and save them as separate frames in an output directory.
    
    Args:
        input_loc: Input video file.
        output_loc: Output directory to save the frames.
    Usage:
        video_to_frames('video_folder/video.mp4', 'video_folder/video/')
    Returns:
        None
    """
    import time
    import cv2
    
    time_start = time.time()
    cap = cv2.VideoCapture(input_loc)
    video_length = int(cap.get(cv2.cv.CV_CAP_PROP_FRAME_COUNT)) - 1
    print "Number of frames: ", video_length
    count = 0
    print ("Converting video..\n")
    while cap.isOpened():
        ret,frame = cap.read()
        cv2.imwrite(output_loc + "/%d.jpg" % (count+1), frame)
        count = count + 1
        if (count > (video_length-1)):
            time_end = time.time()
            cap.release()
            print "Done extracting frames.\n%d frames extracted" %count
            print "It took %d seconds for conversion." %(time_end-time_start)
            break
