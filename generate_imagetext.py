from PIL import Image
import numpy as np
path='FingerprintColorImageDatabase .v1/FingerprintColorImageDatabase .v1/'
for k in range(1,31):
    for l in range(1,6):
        img=Image.open(path+'sub'+str(k)+'/'+str(k)+str(l)+'.jpg')
        img=np.array(img)
        img_arr=[] 
        for i in range(200):
            img_arr.append([])
            for j in range(200):
                if img[i][j][0]<200:
                    img_arr[-1].append(1)
                else:
                    img_arr[-1].append(0) 
        output_file=open('bin_image/bin_image'+str(k)+str(l)+'.txt','w') 
        for row in img_arr:
            for item in row:
                output_file.write(str(item)+' ')
            output_file.write('\n')