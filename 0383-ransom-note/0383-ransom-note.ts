function canConstruct(ransomNote: string, magazine: string): boolean {
    for (const letter of magazine) {
        ransomNote = ransomNote.replace(letter,"");
    }

    if (!ransomNote) {
        return true;
    }
    return false;
};