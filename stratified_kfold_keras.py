'''
Author: Arun Das (arun.das@my.utsa.edu)

Description: Training part of the K-Fold Stratified training loop for Keras training. 
Write a function `define_model()` to return the model architecture. Also, save a separate
test array to test it based on the same criteria.
'''

# fix random seed for reproducibility
seed = 7
np.random.seed(seed)

X_array_, X_test, Y_array_, y_test = train_test_split(
    X_array, Y_array, test_size=0.3, random_state=seed)

reduce_lr = ReduceLROnPlateau(monitor='loss', factor=0.2, patience=15, min_lr=0.001)

kfold = StratifiedKFold(n_splits=5, shuffle=True, random_state=seed)

accuracies = []
precisions = []
recalls = []
f1s = []
count = 1

for train, test in kfold.split(X_array_, Y_array_):
    print("Processing Fold ", count)
    count += 1
    model = define_model()
    model.compile(loss='binary_crossentropy', optimizer='adam', metrics=['accuracy'])
    history = model.fit(X_array[train], Y_array[train], 
                        epochs=100, batch_size=256, verbose=0, 
                        validation_data=(X_array[test], Y_array[test]),
                        shuffle=True,
                        callbacks=[reduce_lr])

    plot_history(history)

    test_output = model.evaluate(X_test, y_test, verbose=0)
    y_pred = model.predict(X_test)
    y_pred_binary = np.round(np.clip(y_pred, 0, 1)).flatten()
    precision = precision_score(y_test, y_pred_binary)
    recall = recall_score(y_test, y_pred_binary)
    f1 = f1_score(y_test, y_pred_binary)
    print("Accuracy: {:.2f}%, Recall: {:.3f}, Precision: {:.3f}, F1: {:.3f}".format(test_output[1]*100, recall, precision, f1))
    
    accuracies.append(test_output[1]*100)
    precisions.append(precision)
    recalls.append(recall)
    f1s.append(f1)
    
    if test_output[1] > 0.8:
        model_name = '_StutterNet_C_upscaled_S1S2_subject_' + str(subject) + '_'
        model_path = '../trained_models/' + str(datetime.date.today()) + model_name + '{:.3f}'.format(test_output[1])[-3:]
        print("Saving to: ", model_path + '.h5')
        model.save(model_path + '.h5')
        with open(model_path + '_history.pkl','wb') as f: pickle.dump(model.history.history, f)
        with open(model_path + '_params.pkl','wb') as f: pickle.dump(model.history.params, f)

    ##     with open(model_path + '_history.pkl','rb') as f: history2 = pickle.load(f)
    ##     with open(model_path + '_params.pkl','rb') as f: params2 = pickle.load(f)

print("Training Statistics")
metrics_df = pd.DataFrame.from_dict({'Accuracy': accuracies, 'F1': f1s, 'Recall': recalls, 'Precision': precisions})
print(metrics_df.describe())
